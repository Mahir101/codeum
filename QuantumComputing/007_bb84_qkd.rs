/// BB84 Quantum Key Distribution Protocol in Rust
/// Demonstrates secure key exchange using quantum polarization states.

use rand::Rng;

#[derive(Debug, Clone, Copy, PartialEq)]
enum Basis { Rectilinear, Diagonal } // + or x

#[derive(Debug, Clone, Copy, PartialEq)]
enum Bit { Zero, One }

pub struct BB84 {
    num_bits: usize,
}

impl BB84 {
    pub fn new(num_bits: usize) -> Self {
        BB84 { num_bits }
    }

    pub fn simulate(&self) {
        let mut rng = rand::rng();

        // 1. Alice generates random bits and bases
        let alice_bits: Vec<Bit> = (0..self.num_bits).map(|_| if rng.gen_bool(0.5) { Bit::One } else { Bit::Zero }).collect();
        let alice_bases: Vec<Basis> = (0..self.num_bits).map(|_| if rng.gen_bool(0.5) { Basis::Diagonal } else { Basis::Rectilinear }).collect();

        // 2. Alice sends qubits to Bob (simulated as bit+basis pairs)
        // 3. Bob chooses random bases to measure
        let bob_bases: Vec<Basis> = (0..self.num_bits).map(|_| if rng.gen_bool(0.5) { Basis::Diagonal } else { Basis::Rectilinear }).collect();
        
        // 4. Bob measures Alice's bits
        let mut bob_bits = Vec::new();
        for i in 0..self.num_bits {
            if alice_bases[i] == bob_bases[i] {
                // Bob uses same basis, gets same bit
                bob_bits.push(alice_bits[i]);
            } else {
                // Bob uses different basis, gets random result (collapses state)
                bob_bits.push(if rng.gen_bool(0.5) { Bit::One } else { Bit::Zero });
            }
        }

        // 5. Alice and Bob reveal bases and keep bits where bases matched
        let mut shared_key_alice = Vec::new();
        let mut shared_key_bob = Vec::new();
        for i in 0..self.num_bits {
            if alice_bases[i] == bob_bases[i] {
                shared_key_alice.push(alice_bits[i]);
                shared_key_bob.push(bob_bits[i]);
            }
        }

        println!("BB84 Simulation on {} initial bits:", self.num_bits);
        println!("Bases matched for {} bits.", shared_key_alice.len());
        println!("Final Shared Key (Alice): {:?}", shared_key_alice);
        println!("Final Shared Key (Bob):   {:?}", shared_key_bob);
        
        let success = shared_key_alice == shared_key_bob;
        println!("Key exchange successful: {}", success);
    }
}

fn main() {
    let protocol = BB84::new(20);
    protocol.simulate();
}
