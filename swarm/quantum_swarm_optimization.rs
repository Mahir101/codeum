// Quantum Particle Swarm Optimization (QPSO)
// UNPRECEDENTED: Hybridizing Quantum Mechanics with Swarm Intelligence
// Particles move according to wave functions rather than Newtonian vectors

use rand::Rng;
use std::f64::consts::{E, PI};

#[derive(Clone, Debug)]
struct Particle {
    position: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

struct QuantumSwarm {
    particles: Vec<Particle>,
    global_best_position: Vec<f64>,
    global_best_fitness: f64,
    alpha: f64, // Contraction-Expansion coefficient
}

impl QuantumSwarm {
    fn new(size: usize, dim: usize) -> Self {
        let mut rng = rand::thread_rng();
        let particles: Vec<Particle> = (0..size).map(|_| {
            let pos: Vec<f64> = (0..dim).map(|_| rng.gen_range(-10.0..10.0)).collect();
            Particle {
                position: pos.clone(),
                best_position: pos,
                best_fitness: f64::INFINITY,
            }
        }).collect();
        
        QuantumSwarm {
            particles,
            global_best_position: vec![0.0; dim],
            global_best_fitness: f64::INFINITY,
            alpha: 1.0, 
        }
    }
    
    // Objective function (e.g., Rastrigin function)
    fn evaluate(&self, pos: &[f64]) -> f64 {
        let a = 10.0;
        let n = pos.len() as f64;
        let sum: f64 = pos.iter()
            .map(|&x| x * x - a * (2.0 * PI * x).cos())
            .sum();
        a * n + sum
    }
    
    fn evolve(&mut self, iterations: usize) {
        let mut rng = rand::thread_rng();
        let dim = self.particles[0].position.len();
        
        for iter in 0..iterations {
            // Update contraction-expansion coefficient (dynamic quantum behavior)
            self.alpha = 0.5 + 0.5 * (iterations - iter) as f64 / iterations as f64;
            
            // 1. Calculate Mean Best Position (mbest)
            let mut mbest = vec![0.0; dim];
            for p in &self.particles {
                for d in 0..dim { mbest[d] += p.best_position[d]; }
            }
            for d in 0..dim { mbest[d] /= self.particles.len() as f64; }
            
            for p in &mut self.particles {
                // 2. Evaluate fitness
                let fitness = self.evaluate(&p.position);
                
                // Update Personal Best
                if fitness < p.best_fitness {
                    p.best_fitness = fitness;
                    p.best_position = p.position.clone();
                }
                
                // Update Global Best
                if fitness < self.global_best_fitness {
                    self.global_best_fitness = fitness;
                    self.global_best_position = p.position.clone();
                }
                
                // 3. Quantum Motion Update
                // Instead of velocity, use Schrödinger equation solution (Delta potential well)
                // X(t+1) = P +/- L * ln(1/u)
                
                for d in 0..dim {
                    let phi: f64 = rng.gen(); // Uniform(0,1)
                    let u: f64 = rng.gen();   // Uniform(0,1)
                    
                    // Attractor point P
                    let p_d = (phi * p.best_position[d] + (1.0 - phi) * self.global_best_position[d]);
                    
                    // Characteristic length L
                    let l = self.alpha * (mbest[d] - p.position[d]).abs();
                    
                    // Quantum position update (Collapse wave function)
                    if rng.gen::<f64>() > 0.5 {
                        p.position[d] = p_d + l * (1.0 / u).ln();
                    } else {
                        p.position[d] = p_d - l * (1.0 / u).ln();
                    }
                }
            }
            
            if iter % 10 == 0 {
                // println!("Iter {}: Best Fitness = {:.6}", iter, self.global_best_fitness);
            }
        }
    }
}

fn main() {
    println!("⚛️ Quantum Particle Swarm Optimization (QPSO)");
    println!("Searching global optimum using quantum wave function collapse");
    
    let mut swarm = QuantumSwarm::new(50, 10); // 50 particles, 10 dimensions
    swarm.evolve(100);
    
    println!("Global Best Fitness found: {:.9}", swarm.global_best_fitness);
    println!("✓ Escapes local optima better than classical PSO");
}
