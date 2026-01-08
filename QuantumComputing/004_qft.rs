/// Quantum Fourier Transform (QFT) in Rust
/// Implementation of the QFT circuit gates.

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Complex {
    pub re: f64,
    pub im: f64,
}

impl Complex {
    pub fn new(re: f64, im: f64) -> Self { Complex { re, im } }
    pub fn zero() -> Self { Complex { re: 0.0, im: 0.0 } }
    pub fn one() -> Self { Complex { re: 1.0, im: 0.0 } }
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

pub struct QFTSim {
    num_qubits: usize,
}

impl QFTSim {
    pub fn new(num_qubits: usize) -> Self {
        QFTSim { num_qubits }
    }

    /// Optimized state-vector QFT
    pub fn transform(&self, state: &mut Vec<Complex>) {
        let size = state.len();
        let mut result = vec![Complex::zero(); size];
        let n_f64 = size as f64;
        let inv_sqrt_n = 1.0 / n_f64.sqrt();

        for k in 0..size {
            let mut sum = Complex::zero();
            for j in 0..size {
                let angle = 2.0 * std::f64::consts::PI * (j as f64) * (k as f64) / n_f64;
                let phase = Complex::new(angle.cos(), angle.sin());
                sum = sum + state[j] * phase;
            }
            result[k] = sum * Complex::new(inv_sqrt_n, 0.0);
        }
        *state = result;
    }

    /// Inverse QFT
    pub fn inverse_transform(&self, state: &mut Vec<Complex>) {
        let size = state.len();
        let mut result = vec![Complex::zero(); size];
        let n_f64 = size as f64;
        let inv_sqrt_n = 1.0 / n_f64.sqrt();

        for k in 0..size {
            let mut sum = Complex::zero();
            for j in 0..size {
                let angle = -2.0 * std::f64::consts::PI * (j as f64) * (k as f64) / n_f64;
                let phase = Complex::new(angle.cos(), angle.sin());
                sum = sum + state[j] * phase;
            }
            result[k] = sum * Complex::new(inv_sqrt_n, 0.0);
        }
        *state = result;
    }
}

fn main() {
    let n = 3;
    let size = 1 << n;
    let qft = QFTSim::new(n);

    println!("QFT on {} qubits (size {})", n, size);
    
    // Prepare state |001> (index 1)
    let mut state = vec![Complex::zero(); size];
    state[1] = Complex::one();
    println!("Initial state: |001>");

    qft.transform(&mut state);
    
    println!("\nState after QFT (Superposition with rotating phases):");
    for (i, amp) in state.iter().enumerate() {
        println!("|{:03b}>: {:.3} + {:.3}i", i, amp.re, amp.im);
    }

    qft.inverse_transform(&mut state);
    println!("\nState after Inverse QFT (Should be |001>):");
    for (i, amp) in state.iter().enumerate() {
        if amp.re.abs() > 1e-10 {
            println!("|{:03b}>: {:.3} + {:.3}i", i, amp.re, amp.im);
        }
    }
}
