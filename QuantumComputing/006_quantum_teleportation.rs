/// Quantum Teleportation Protocol in Rust
/// Demonstrates the transmission of a quantum state using entanglement.

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

/// Simulation of Teleportation
pub struct Teleportation {
    // 3 Qubits: 0 (Alice's payload), 1 (Alice's entangled), 2 (Bob's entangled)
    state: Vec<Complex>,
}

impl Teleportation {
    pub fn new(alpha: Complex, beta: Complex) -> Self {
        let mut state = vec![Complex::zero(); 8];
        // Initialize qubit 0 to alpha|0> + beta|1>
        state[0] = alpha; // |000>
        state[4] = beta;  // |100> (binary 100 is index 4 if qubit 0 is MSB)
        // Wait, index mapping depends on endianness. We'll use: index = q0*4 + q1*2 + q2
        Teleportation { state }
    }

    pub fn run(&mut self) {
        println!("1. Creating Entanglement (Bell pair) between Alice(1) and Bob(2)...");
        self.apply_h(1);
        self.apply_cx(1, 2);

        println!("2. Alice performs Bell Measurement on her qubits (0 and 1)...");
        self.apply_cx(0, 1);
        self.apply_h(0);

        println!("3. Alice measures qubits 0 and 1. (Simulation: collapsing and identifying state)");
        // In real quantum computing, Alice would send 2 classical bits.
        // Here we simulate the state of Bob's qubit 2 based on all 8 amplitudes.
        // We'll extract Bob's qubit state for each Alice measurement outcome.
    }

    fn apply_h(&mut self, q: usize) {
        let inv_sqrt2 = 1.0 / 2.0f64.sqrt();
        let h_val = Complex::new(inv_sqrt2, 0.0);
        let mut new_state = vec![Complex::zero(); 8];
        for i in 0..8 {
            let bit = (i >> (2-q)) & 1;
            let partner = i ^ (1 << (2-q));
            if bit == 0 {
                new_state[i] = (self.state[i] + self.state[partner]) * h_val;
            } else {
                new_state[i] = (self.state[partner] - self.state[i]) * h_val;
            }
        }
        self.state = new_state;
    }
    
    // Subtraction for Complex (needed for H gate)
    // Adding it inline or to struct

    fn apply_cx(&mut self, c: usize, t: usize) {
        let mut new_state = self.state.clone();
        for i in 0..8 {
            let control_bit = (i >> (2-c)) & 1;
            if control_bit == 1 {
                let j = i ^ (1 << (2-t));
                new_state[j] = self.state[i];
            }
        }
        self.state = new_state;
    }

    pub fn verify_bob(&self) {
        println!("\nBob's Qubit State after teleportation (analyzing conditional results):");
        // alice_result 00: |00q> -> Bob has alpha|0> + beta|1>
        // alice_result 01: |01q> -> Bob has alpha|1> + beta|0> (needs X)
        // alice_result 10: |10q> -> Bob has alpha|0> - beta|1> (needs Z)
        // alice_result 11: |11q> -> Bob has alpha|1> - beta|0> (needs XZ)
        
        for alice_bits in 0..4 {
            let i0 = alice_bits << 1;
            let i1 = (alice_bits << 1) | 1;
            let amp0 = self.state[i0];
            let amp1 = self.state[i1];
            println!("Alice outcome |{:02b}>: Bob is in state {:.3}|0> + {:.3}|1>", 
                alice_bits, amp0, amp1);
        }
    }
}

// Fixed complex subtraction
impl std::ops::Sub for Complex {
    type Output = Self;
    fn sub(self, other: Self) -> Self { Complex::new(self.re - other.re, self.im - other.im) }
}

fn main() {
    let alpha = Complex::new(0.6, 0.0);
    let beta = Complex::new(0.8, 0.0);
    println!("Alice wants to teleport state: {:.2}|0> + {:.2}|1>", alpha.re, beta.re);

    let mut tele = Teleportation::new(alpha, beta);
    tele.run();
    tele.verify_bob();
}
