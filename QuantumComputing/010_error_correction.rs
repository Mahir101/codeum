/// Quantum Error Correction (3-Qubit Bit-Flip Code) in Rust
/// Demonstrates how to detect and correct single-qubit bit-flip errors.

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Qubit {
    pub a: f64, // alpha |0>
    pub b: f64, // beta  |1>
}

impl Qubit {
    pub fn new(a: f64, b: f64) -> Self { Qubit { a, b } }
}

pub struct ErrorCorrectionSim {
    state: Vec<f64>, // Statevector for 3 qubits (8 amplitudes)
}

impl ErrorCorrectionSim {
    pub fn new(source: Qubit) -> Self {
        // Encoding: |psi>|00> -> alpha|000> + beta|111>
        let mut state = vec![0.0; 8];
        state[0] = source.a; // |000>
        state[7] = source.b; // |111>
        ErrorCorrectionSim { state }
    }

    /// Simulate a random bit-flip error on one of the 3 qubits
    pub fn apply_error(&mut self, qubit_idx: usize) {
        println!("Error occurred on qubit {}!", qubit_idx);
        let mut new_state = vec![0.0; 8];
        for i in 0..8 {
            let j = i ^ (1 << (2 - qubit_idx));
            new_state[j] = self.state[i];
        }
        self.state = new_state;
    }

    /// Syndrome Measurement and Correction
    /// Detects parity between (0,1) and (1,2)
    pub fn correct(&mut self) {
        println!("Measuring syndromes...");
        
        // In a real system, we'd measure ancilla qubits.
        // Here we analyze the collapsed state to see where the flip happened.
        let mut flipped_qubit = None;
        
        // Find which basis states have non-zero amplitudes
        let active_states: Vec<usize> = self.state.iter().enumerate()
            .filter(|&(_, &amp)| amp.abs() > 1e-6)
            .map(|(i, _)| i).collect();
        
        // Analyze the mapping: if error on q0, |000>->|100> (4) and |111>->|011> (3)
        // If error on q1, |000>->|010> (2) and |111>->|101> (5)
        // If error on q2, |000>->|001> (1) and |111>->|110> (6)
        
        if active_states.contains(&4) || active_states.contains(&3) { flipped_qubit = Some(0); }
        else if active_states.contains(&2) || active_states.contains(&5) { flipped_qubit = Some(1); }
        else if active_states.contains(&1) || active_states.contains(&6) { flipped_qubit = Some(2); }

        if let Some(q) = flipped_qubit {
            println!("Syndrome analysis: Error detected on qubit {}. Correcting...", q);
            self.apply_error(q); // Flipping again corrects it
        } else {
            println!("No error detected.");
        }
    }

    pub fn display(&self) {
        for (i, &amp) in self.state.iter().enumerate() {
            if amp.abs() > 1e-6 {
                println!("|{:03b}>: {:.3}", i, amp);
            }
        }
    }
}

fn main() {
    let psi = Qubit::new(0.6, 0.8);
    println!("Initial logical qubit: 0.6|0> + 0.8|1>");

    let mut sim = ErrorCorrectionSim::new(psi);
    println!("\nEncoded state (|000> and |111>):");
    sim.display();

    println!("\n--- Simulating environment noise ---");
    sim.apply_error(1); // Flip middle qubit
    sim.display();

    println!("\n--- Quantum Error Correction Protocol ---");
    sim.correct();
    
    println!("\nFinal State (Should be back to encoded form):");
    sim.display();
}
