/*
 * Unprecedented Algorithm: Reversible Computing (Fredkin Gate)
 * Category: Physics / Computation
 */

// ==========================================
// INTUITION & IMAGINATION
// ==========================================
// Conventional computers generate heat (entropy) because they destroy information.
// AND gate: Inputs (0, 1) -> Output (0).
// if I tell you Output is 0, can you tell me what the Inputs were?
// No. It could be (0,0), (0,1), or (1,0). Information is lost.
// Landauer's Principle says: Erasing 1 bit costs k*T*ln(2) energy.
//
// Imagination:
// Imagine a billiard ball computer. Balls collide perfectly elastically.
// If you film the computation and play it BACKWARDS, it looks perfectly valid (Physics is time-reversible).
// This requires gates that have same number of Inputs and Outputs.
//
// The Fredkin Gate (CSWAP):
// Inputs: (Control, A, B)
// - If Control = 0: Output (Control, A, B) (No change).
// - If Control = 1: Output (Control, B, A) (Swap A and B).
//
// This gate is Universal. You can build ANY logic circuit using just this gate,
// and it consumes theoretically ZERO energy (adiabatic computing).

// ==========================================
// REAL WORLD APPLICATIONS
// ==========================================
// 1. Quantum Computing: All Quantum Gates MUST be reversible (Unitary transformations).
// 2. Low-Power Chips: Designing ultra-low power ASICs.
// 3. Cryptography: Reversible functions are easier to analyze for bijectivity.

#[derive(Debug, Clone, Copy, PartialEq)]
struct Bit(bool);

fn fredkin_gate(c: Bit, a: Bit, b: Bit) -> (Bit, Bit, Bit) {
    if c.0 {
        (c, b, a) // Swap
    } else {
        (c, a, b) // No op
    }
}

// Emulating AND Gate using Fredkin
// To do AND(x, y), we set inputs to (x, y, 0).
// If x=1: Output is (1, 0, y) -> 3rd output is y (which is 1 AND y).
// Wait. 
// Standard mapping:
// Input (x, y, 0) -> Output (x, z, w). w = x AND y?
// Let's trace C=x, A=y, B=0.
// If x=0: Out=(0, y, 0). 3rd is 0. (0 AND y = 0). Correct.
// If x=1: Out=(1, 0, y). 3rd is y. (1 AND y = y). Correct.
// So Fredkin(x, y, 0) provides x AND y on the 3rd line.
fn reversible_and(x: Bit, y: Bit) -> Bit {
    let (_, _, res) = fredkin_gate(x, y, Bit(false));
    res
}

fn main() {
    println!("Reversible Computing Logic");
    let x = Bit(true);
    let y = Bit(false);
    println!("AND(1, 0) = {:?}", reversible_and(x, y)); // false
}
