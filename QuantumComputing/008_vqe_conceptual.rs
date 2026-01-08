/// Variational Quantum Eigensolver (VQE) Conceptual Simulation in Rust
/// Demonstrates the hybrid quantum-classical optimization loop.

use std::f64::consts::PI;

pub struct VQESim {
    theta: f64, // Parametric angle for the ansatz
}

impl VQESim {
    pub fn new(initial_theta: f64) -> Self {
        VQESim { theta: initial_theta }
    }

    /// Simulation of a Quantum Circuit (Ansatz)
    /// Circuit: H(0) -> RY(theta, 0) -> CNOT(0, 1)
    /// Returns the expectation value of some Hamiltonian H
    pub fn get_expectation(&self) -> f64 {
        // Conceptual energy surface: E(theta) = cos(theta) + 0.5 * sin(2*theta)
        // In real VQE, this would be computed by running the circuit on a QPU
        self.theta.cos() + 0.5 * (2.0 * self.theta).sin()
    }

    /// Classical Optimizer (Gradient Descent)
    pub fn optimize(&mut self, learning_rate: f64, steps: usize) {
        println!("Starting optimization from theta = {:.4}...", self.theta);
        
        for i in 0..steps {
            let energy = self.get_expectation();
            
            // Numerical gradient: (E(t+dt) - E(t-dt)) / 2dt
            let dt = 0.001;
            let e_plus = {
                let mut temp = VQESim::new(self.theta + dt);
                temp.get_expectation()
            };
            let e_minus = {
                let mut temp = VQESim::new(self.theta - dt);
                temp.get_expectation()
            };
            let grad = (e_plus - e_minus) / (2.0 * dt);
            
            // Update parameter
            self.theta -= learning_rate * grad;
            
            if i % 10 == 0 || i == steps - 1 {
                println!("Step {}: Energy = {:.6}, Theta = {:.4}", i, energy, self.theta);
            }
        }
    }
}

fn main() {
    println!("VQE: Hybrid Quantum-Classical Algorithm Simulation");
    println!("Goal: Find the minimum energy (ground state) of a Hamiltonian\n");

    let mut vqe = VQESim::new(0.0); // Start at theta = 0
    vqe.optimize(0.1, 100);

    println!("\nOptimal Parameter Found: theta = {:.4}", vqe.theta);
    println!("Minimum Energy (Ground State): {:.6}", vqe.get_expectation());
}
