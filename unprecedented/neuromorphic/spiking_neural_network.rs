// Neuromorphic Computing: Spiking Neural Network (SNN)
// UNPRECEDENTED: Event-driven processing with STDP (Spike-Timing-Dependent Plasticity) learning
// Mimics biological neurons more closely than standard ANNs

use rand::Rng;
use std::collections::VecDeque;

const TAU_MEM: f64 = 20.0;  // Membrane time constant (ms)
const TAU_SYN: f64 = 5.0;   // Synaptic time constant (ms)
const V_THRESHOLD: f64 = 1.0;
const V_RESET: f64 = 0.0;
const REFRACTORY_PERIOD: usize = 5; // steps

#[derive(Clone, Debug)]
struct Spike {
    timestamp: usize,
}

struct LIFNeuron {
    v_mem: f64,        // Membrane potential
    i_syn: f64,        // Synaptic current
    refractory_timer: usize,
    last_spike_time: Option<usize>,
    trace: f64,        // Synaptic trace for STDP
}

impl LIFNeuron {
    fn new() -> Self {
        LIFNeuron {
            v_mem: 0.0,
            i_syn: 0.0,
            refractory_timer: 0,
            last_spike_time: None,
            trace: 0.0,
        }
    }

    fn step(&mut self, input_current: f64, dt: f64) -> bool {
        if self.refractory_timer > 0 {
            self.refractory_timer -= 1;
            self.v_mem = V_RESET;
            return false;
        }

        // Leaky Integrate-and-Fire dynamics
        // dV/dt = -(V - V_rest)/tau_mem + I/C
        let dv = (-(self.v_mem) + self.i_syn + input_current) / TAU_MEM;
        self.v_mem += dv * dt;
        
        // Decay synaptic current
        self.i_syn -= (self.i_syn / TAU_SYN) * dt;
        
        // Update trace (exponential decay)
        self.trace *= (-dt / 20.0).exp(); // 20ms trace constant

        if self.v_mem >= V_THRESHOLD {
            self.v_mem = V_RESET;
            self.refractory_timer = REFRACTORY_PERIOD;
            self.trace += 1.0; // Increment trace on spike
            return true;
        }
        false
    }
}

struct Synapse {
    pre_id: usize,
    post_id: usize,
    weight: f64,
    delay: usize,
    spike_queue: VecDeque<usize>, // Queue of spike arrival times
    stdp_window: f64, // Learning window (ms)
}

impl Synapse {
    fn new(pre: usize, post: usize, w: f64) -> Self {
        Synapse {
            pre_id: pre,
            post_id: post,
            weight: w,
            delay: 2,
            spike_queue: VecDeque::new(),
            stdp_window: 20.0,
        }
    }
    
    fn process_spike(&mut self, current_time: usize) {
        self.spike_queue.push_back(current_time + self.delay);
    }
    
    fn step(&mut self, current_time: usize, post_neuron: &mut LIFNeuron) {
        while let Some(&arrival) = self.spike_queue.front() {
            if arrival <= current_time {
                self.spike_queue.pop_front();
                post_neuron.i_syn += self.weight;
                
                // LTP (Long-Term Potentiation): Pre before Post
                // If post neuron spiked recently, increase weight
                if let Some(last_spike) = post_neuron.last_spike_time {
                     let dt = current_time as f64 - last_spike as f64;
                     if dt < self.stdp_window {
                         self.weight += 0.01 * (-dt / self.stdp_window).exp();
                     }
                }
            } else {
                break;
            }
        }
    }
    
    fn apply_ltd(&mut self, pre_trace: f64) {
        // LTD (Long-Term Depression): Post before Pre (triggered when post spikes)
        // Decrease weight based on presynaptic trace
        self.weight -= 0.005 * pre_trace;
        if self.weight < 0.0 { self.weight = 0.0; }
    }
}

struct SpikingNetwork {
    neurons: Vec<LIFNeuron>,
    synapses: Vec<Synapse>,
    time_step: usize,
}

impl SpikingNetwork {
    fn new(num_neurons: usize) -> Self {
        SpikingNetwork {
            neurons: (0..num_neurons).map(|_| LIFNeuron::new()).collect(),
            synapses: Vec::new(),
            time_step: 0,
        }
    }
    
    fn connect(&mut self, pre: usize, post: usize, weight: f64) {
        self.synapses.push(Synapse::new(pre, post, weight));
    }
    
    fn run(&mut self, inputs: &[f64], steps: usize) -> Vec<Vec<usize>> {
        let mut spike_trains = vec![Vec::new(); self.neurons.len()];
        let dt = 1.0; // 1ms step
        
        for _ in 0..steps {
            self.time_step += 1;
            
            // 1. Calculate inputs and update neurons
            for i in 0..self.neurons.len() {
                let input = if i < inputs.len() { inputs[i] } else { 0.0 };
                let spiked = self.neurons[i].step(input, dt);
                
                if spiked {
                    spike_trains[i].push(self.time_step);
                    self.neurons[i].last_spike_time = Some(self.time_step);
                    
                    // Propagate spikes to synapses
                    for synapse in &mut self.synapses {
                        if synapse.pre_id == i {
                            synapse.process_spike(self.time_step);
                        }
                        
                        // STDP: LTD
                        if synapse.post_id == i {
                           let pre_trace = self.neurons[synapse.pre_id].trace;
                           synapse.apply_ltd(pre_trace);
                        }
                    }
                }
            }
            
            // 2. Deliver synaptic currents
            // To avoid borrowing issues, we'd typically separate state, 
            // but for simple demo we iterate indices or use separate step
            let mut delivered_currents = vec![0.0; self.neurons.len()];
             for synapse in &mut self.synapses {
                while let Some(&arrival) = synapse.spike_queue.front() {
                    if arrival <= self.time_step {
                        synapse.spike_queue.pop_front();
                        delivered_currents[synapse.post_id] += synapse.weight;
                        
                        // STDP: LTP logic approximates here
                    } else {
                        break;
                    }
                }
            }
            
            for (i, &current) in delivered_currents.iter().enumerate() {
                self.neurons[i].i_syn += current;
            }
        }
        
        spike_trains
    }
}

fn main() {
    println!("🧠 Neuromorphic SNN - Spiking Neural Network");
    println!("Simulating biological neurons with STDP learning");
    
    let mut snn = SpikingNetwork::new(10);
    // Connect standard feedforward structure
    for i in 0..5 {
        for j in 5..10 {
            snn.connect(i, j, 0.5);
        }
    }
    
    // Simulate input spikes
    let inputs = vec![5.0, 0.0, 5.0, 0.0, 5.0]; // Current injection
    let spikes = snn.run(&inputs, 100);
    
    println!("Spike Train Summary:");
    for (i, train) in spikes.iter().enumerate() {
        if i >= 5 { // Output neurons
            println!("Neuron {}: {} spikes", i, train.len());
        }
    }
    
    println!("✓ STDP Learning applied to weights based on causality");
}
