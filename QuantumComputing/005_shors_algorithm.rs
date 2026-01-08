/// Shor's Algorithm (Conceptual Period Finding) in Rust
/// Demonstrates the core logic of Shor's algorithm: finding the period 'r' of f(x) = a^x mod N.

use std::collections::HashSet;

/// Classical modular exponentiation for verification
fn mod_pow(mut base: u64, mut exp: u64, n: u64) -> u64 {
    let mut res = 1;
    base %= n;
    while exp > 0 {
        if exp % 2 == 1 { res = (res * base) % n; }
        base = (base * base) % n;
        exp /= 2;
    }
    res
}

/// Simulation of the Quantum Period Finding
/// In a real QPU, this would use QFT and phase estimation
pub struct ShorSim {
    a: u64,
    n: u64,
}

impl ShorSim {
    pub fn new(a: u64, n: u64) -> Self {
        ShorSim { a, n }
    }

    /// Finds the period 'r' such that a^r ≡ 1 (mod N)
    /// This implementation simulates the quantum measurement collapse
    pub fn find_period(&self) -> Option<u64> {
        println!("Finding period for {}^x mod {}...", self.a, self.n);
        
        let mut results = Vec::new();
        // The quantum computer would evaluate all x in superposition
        // and then we would measure the state.
        for x in 1..self.n {
            let val = mod_pow(self.a, x, self.n);
            if val == 1 {
                println!("Found period candidate: r = {}", x);
                return Some(x);
            }
            results.push(val);
        }
        None
    }

    /// Classical part of Shor's: computing the factors from the period
    pub fn factorize(&self, r: u64) -> (u64, u64) {
        // Factors are gcd(a^(r/2) ± 1, N)
        let x = mod_pow(self.a, r / 2, self.n);
        let f1 = gcd(x + 1, self.n);
        let f2 = gcd(if x > 1 { x - 1 } else { self.n - (1 - x) }, self.n);
        (f1, f2)
    }
}

fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        a %= b;
        std::mem::swap(&mut a, &mut b);
    }
    a
}

fn main() {
    let n = 15; // Number to factor
    let a = 7;  // Coprime base
    
    println!("Shor's Algorithm Simulation: Factorizing N = {}", n);
    
    let shor = ShorSim::new(a, n);
    if let Some(r) = shor.find_period() {
        if r % 2 == 0 {
            let (f1, f2) = shor.factorize(r);
            println!("Factors found: {} and {}", f1, f2);
            assert_eq!(f1 * f2 % n, 0);
        } else {
            println!("Found odd period {}, try a different 'a'", r);
        }
    }
}
