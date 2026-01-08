/// Quantum Circuit Implementation in Rust
/// Mimics Qiskit-style circuit building and execution.

use std::fmt;

/// Ported from 001_basics logic for standalone circuit simulation
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Complex {
    pub re: f64,
    pub im: f64,
}

impl Complex {
    pub fn new(re: f64, im: f64) -> Self { Complex { re, im } }
    pub fn zero() -> Self { Complex { re: 0.0, im: 0.0 } }
    pub fn one() -> Self { Complex { re: 1.0, im: 0.0 } }
    pub fn norm_sq(&self) -> f64 { self.re * self.re + self.im * self.im }
}

impl std::ops::Add for Complex {
    type Output = Self;
    fn add(self, other: Self) -> Self { Complex::new(self.re + other.re, self.im + other.im) }
}

impl std::ops::Mul for Complex {
    type Output = Self;
    fn mul(self, other: Self) -> Self {
        Complex::new(self.re * other.re - self.im * other.im, self.re * other.im + self.im * other.re)
    }
}

/// Represents a quantum gate application
pub enum GateType {
    H(usize),          // Hadamard on qubit i
    X(usize),          // Pauli-X on qubit i
    CX(usize, usize),  // CNOT with control c and target t
    Z(usize),          // Pauli-Z on qubit i
}

pub struct QuantumCircuit {
    num_qubits: usize,
    gates: Vec<GateType>,
}

impl QuantumCircuit {
    pub fn new(num_qubits: usize) -> Self {
        QuantumCircuit {
            num_qubits,
            gates: Vec::new(),
        }
    }

    pub fn h(&mut self, qubit: usize) {
        self.gates.push(GateType::H(qubit));
    }

    pub fn x(&mut self, qubit: usize) {
        self.gates.push(GateType::X(qubit));
    }

    pub fn cx(&mut self, control: usize, target: usize) {
        self.gates.push(GateType::CX(control, target));
    }

    pub fn z(&mut self, qubit: usize) {
        self.gates.push(GateType::Z(qubit));
    }

    /// Execute the circuit and return the state vector
    pub fn execute(&self) -> Vec<Complex> {
        let size = 1 << self.num_qubits;
        let mut state = vec![Complex::zero(); size];
        state[0] = Complex::one(); // Start at |0...0>

        for gate in &self.gates {
            match gate {
                GateType::H(q) => self.apply_h(&mut state, *q),
                GateType::X(q) => self.apply_x(&mut state, *q),
                GateType::CX(c, t) => self.apply_cx(&mut state, *c, *t),
                GateType::Z(q) => self.apply_z(&mut state, *q),
            }
        }
        state
    }

    fn apply_h(&self, state: &mut Vec<Complex>, q: usize) {
        let inv_sqrt2 = 1.0 / 2.0f64.sqrt();
        let h_plus = Complex::new(inv_sqrt2, 0.0);
        let h_minus = Complex::new(-inv_sqrt2, 0.0);
        
        for i in 0..(1 << self.num_qubits) {
            if (i >> q) & 1 == 0 {
                let j = i | (1 << q);
                let val_i = state[i];
                let val_j = state[j];
                state[i] = (val_i + val_j) * h_plus;
                state[j] = (val_i * h_plus) + (val_j * h_minus);
            }
        }
    }

    fn apply_x(&self, state: &mut Vec<Complex>, q: usize) {
        for i in 0..(1 << self.num_qubits) {
            if (i >> q) & 1 == 0 {
                let j = i | (1 << q);
                state.swap(i, j);
            }
        }
    }

    fn apply_z(&self, state: &mut Vec<Complex>, q: usize) {
        let minus_one = Complex::new(-1.0, 0.0);
        for i in 0..(1 << self.num_qubits) {
            if (i >> q) & 1 == 1 {
                state[i] = state[i] * minus_one;
            }
        }
    }

    fn apply_cx(&self, state: &mut Vec<Complex>, c: usize, t: usize) {
        for i in 0..(1 << self.num_qubits) {
            if ((i >> c) & 1 == 1) && ((i >> t) & 1 == 0) {
                let j = i | (1 << t);
                state.swap(i, j);
            }
        }
    }
}

fn main() {
    println!("Creating a Bell State circuit: 1/sqrt(2) (|00> + |11>)");
    let mut qc = QuantumCircuit::new(2);
    qc.h(0);
    qc.cx(0, 1);
    
    let result = qc.execute();
    
    println!("Final Amplitudes:");
    for (i, amp) in result.iter().enumerate() {
        if amp.norm_sq() > 1e-10 {
            println!("|{:02b}>: {:.3} + {:.3}i", i, amp.re, amp.im);
        }
    }
}
