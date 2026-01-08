/// Quantum Computing Basics in Rust
/// Foundational structures for Qubits, Bras, Kets, and Quantum Gates.
/// 
/// This module implements the mathematical foundations of quantum mechanics 
/// used in quantum computing from scratch.

use std::fmt;
use std::ops::{Add, Mul};

/// Complex number structure for quantum amplitudes
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Complex {
    pub re: f64,
    pub im: f64,
}

impl Complex {
    pub fn new(re: f64, im: f64) -> Self {
        Complex { re, im }
    }

    pub fn zero() -> Self {
        Complex { re: 0.0, im: 0.0 }
    }

    pub fn one() -> Self {
        Complex { re: 1.0, im: 0.0 }
    }

    pub fn i() -> Self {
        Complex { re: 0.0, im: 1.0 }
    }

    pub fn norm_sq(&self) -> f64 {
        self.re * self.re + self.im * self.im
    }

    pub fn conj(&self) -> Self {
        Complex::new(self.re, -self.im)
    }
}

impl Add for Complex {
    type Output = Self;
    fn add(self, other: Self) -> Self {
        Complex::new(self.re + other.re, self.im + other.im)
    }
}

impl Mul for Complex {
    type Output = Self;
    fn mul(self, other: Self) -> Self {
        Complex::new(
            self.re * other.re - self.im * other.im,
            self.re * other.im + self.im * other.re,
        )
    }
}

impl fmt::Display for Complex {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:.2} + {:.2}i", self.re, self.im)
    }
}

/// State vector representation of a Quantum system
#[derive(Debug, Clone)]
pub struct StateVector {
    pub amplitudes: Vec<Complex>,
    pub num_qubits: usize,
}

impl StateVector {
    pub fn new(num_qubits: usize) -> Self {
        let size = 1 << num_qubits;
        let mut amplitudes = vec![Complex::zero(); size];
        amplitudes[0] = Complex::one(); // Initialize to |0...0>
        StateVector { amplitudes, num_qubits }
    }

    /// Measurement probability for a basis state
    pub fn probability(&self, state: usize) -> f64 {
        self.amplitudes[state].norm_sq()
    }

    /// Normalize the state vector
    pub fn normalize(&mut self) {
        let norm: f64 = self.amplitudes.iter().map(|c| c.norm_sq()).sum::<f64>().sqrt();
        for a in self.amplitudes.iter_mut() {
            a.re /= norm;
            a.im /= norm;
        }
    }
}

/// Representation of a Quantum Gate as a Unitary Matrix
pub struct QuantumGate {
    pub matrix: Vec<Vec<Complex>>,
    pub name: String,
}

impl QuantumGate {
    /// Hadamard Gate
    pub fn hadamard() -> Self {
        let inv_sqrt2 = 1.0 / 2.0f64.sqrt();
        let h = Complex::new(inv_sqrt2, 0.0);
        let mh = Complex::new(-inv_sqrt2, 0.0);
        QuantumGate {
            name: "H".to_string(),
            matrix: vec![
                vec![h, h],
                vec![h, mh],
            ],
        }
    }

    /// Pauli-X (NOT) Gate
    pub fn pauli_x() -> Self {
        QuantumGate {
            name: "X".to_string(),
            matrix: vec![
                vec![Complex::zero(), Complex::one()],
                vec![Complex::one(), Complex::zero()],
            ],
        }
    }

    /// Pauli-Y Gate
    pub fn pauli_y() -> Self {
        let i = Complex::i();
        let mi = Complex::new(0.0, -1.0);
        QuantumGate {
            name: "Y".to_string(),
            matrix: vec![
                vec![Complex::zero(), mi],
                vec![i, Complex::zero()],
            ],
        }
    }

    /// Pauli-Z Gate
    pub fn pauli_z() -> Self {
        QuantumGate {
            name: "Z".to_string(),
            matrix: vec![
                vec![Complex::one(), Complex::zero()],
                vec![Complex::zero(), Complex::new(-1.0, 0.0)],
            ],
        }
    }
}

fn main() {
    let mut state = StateVector::new(1);
    println!("Initial state: |0>");
    
    let h = QuantumGate::hadamard();
    println!("Applying Hadamard gate...");
    
    // Apply H to |0>
    // Result should be |+> = 1/sqrt(2) (|0> + |1>)
    let mut new_amplitudes = vec![Complex::zero(); 2];
    for i in 0..2 {
        for j in 0..2 {
            new_amplitudes[i] = new_amplitudes[i] + h.matrix[i][j] * state.amplitudes[j];
        }
    }
    state.amplitudes = new_amplitudes;
    
    println!("State after H: {:.3} |0> + {:.3} |1>", state.amplitudes[0], state.amplitudes[1]);
    println!("Probability of |0>: {:.2}", state.probability(0));
    println!("Probability of |1>: {:.2}", state.probability(1));
}
