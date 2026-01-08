/// Grover's Search Algorithm in Rust
/// Demonstrates the amplification of the marked state amplitude.

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

impl std::ops::Sub for Complex {
    type Output = Self;
    fn sub(self, other: Self) -> Self { Complex::new(self.re - other.re, self.im - other.im) }
}

impl std::ops::Mul for Complex {
    type Output = Self;
    fn mul(self, other: Self) -> Self {
        Complex::new(self.re * other.re - self.im * other.im, self.re * other.im + self.im * other.re)
    }
}

pub struct GroverSim {
    num_qubits: usize,
    state: Vec<Complex>,
}

impl GroverSim {
    pub fn new(num_qubits: usize) -> Self {
        let size = 1 << num_qubits;
        let inv_sqrt_n = 1.0 / (size as f64).sqrt();
        // Start with equal superposition (Hadamard on all qubits)
        let state = vec![Complex::new(inv_sqrt_n, 0.0); size];
        GroverSim { num_qubits, state }
    }

    /// Oracle: Flips the sign of the marked state
    pub fn oracle(&mut self, marked_state: usize) {
        self.state[marked_state].re *= -1.0;
        self.state[marked_state].im *= -1.0;
    }

    /// Diffusion Operator (Inversion about the mean)
    pub fn diffuse(&mut self) {
        let size = self.state.len();
        let mean_re: f64 = self.state.iter().map(|c| c.re).sum::<f64>() / (size as f64);
        let mean_im: f64 = self.state.iter().map(|c| c.im).sum::<f64>() / (size as f64);
        
        for amp in self.state.iter_mut() {
            amp.re = 2.0 * mean_re - amp.re;
            amp.im = 2.0 * mean_im - amp.im;
        }
    }

    pub fn run(&mut self, marked_state: usize) {
        let size = 1 << self.num_qubits;
        let iterations = ((size as f64).sqrt() * std::f64::consts::PI / 4.0).floor() as usize;
        
        println!("Running Grover's for {} iterations on {} qubits...", iterations, self.num_qubits);
        
        for i in 0..iterations {
            self.oracle(marked_state);
            self.diffuse();
            println!("Iteration {}: marked prob = {:.4}", i + 1, self.state[marked_state].norm_sq());
        }
    }

    pub fn print_state(&self) {
        for (i, amp) in self.state.iter().enumerate() {
            println!("|{:03b}>: {:.4} (Prob: {:.4})", i, amp.re, amp.norm_sq());
        }
    }
}

fn main() {
    let mut grover = GroverSim::new(3); // 3 qubits, 8 states
    println!("Initial state (Superposition):");
    // grover.print_state();
    
    let target = 0b101; // Marked state |5>
    println!("\nSearching for state |101>...");
    
    grover.run(target);
    
    println!("\nFinal State Probabilities:");
    grover.print_state();
}
