# ⚛️ Quantum Computing in Rust

A high-performance implementation of quantum computing algorithms and simulations entirely in Rust. This library provides foundational structures for quantum states, gates, and complex circuits, mimicking the expressive power of libraries like Qiskit but with Rust's safety and speed.

---

## 🚀 Why Rust for Quantum?
1. **Performance**: Quantum simulations are computationally expensive; Rust's zero-cost abstractions make it ideal for simulators.
2. **Safety**: Rust's borrow checker naturally mirrors the **No-Cloning Theorem**—qubits cannot be copied, only moved or entangled.
3. **Modernity**: Harnessing types for quantum state validation and secure protocols.

---

## 📂 Implementation Index

| File | Description | Key Algorithms |
|------|-------------|----------------|
| `001_basics.rs` | Foundational structures | Qubits, Bras/Kets, H/X/Y/Z Gates |
| `002_circuits.rs` | Circuit building | Bell State, Entanglement, CNOT |
| `003_grover.rs` | Quantum Search | Amplitude Amplification, Oracle |
| `004_qft.rs` | Fourier Transform | Phase rotation, Inverse QFT |
| `005_shors.rs` | Factorization | Period finding simulation |
| `006_teleportation.rs`| Quantum Comms | Entangled state transfer |
| `007_bb84_qkd.rs` | Cryptography | Quantum Key Distribution protocol |
| `008_vqe.rs` | Hybrid QC | Variational Eigensolver optimization |
| `009_qaoa_maxcut.rs` | Optimization | Quantum Approximate Optimization |
| `010_error_correction.rs`| Error Correction | 3-Qubit Bit-Flip code |

---

## 🛠️ Quick Start

To run any of the simulations:

```bash
# Run Shor's Algorithm
rustc 005_shors_algorithm.rs && ./005_shors_algorithm

# Run BB84 Protocol
rustc 007_bb84_qkd.rs && ./007_bb84_qkd
```

---

## 🧠 modern Quantum Concepts Implemented

### 1. Quantum Key Distribution (QKD)
The `BB84` protocol leverages the uncertainty principle to detect eavesdropping during cryptographic key exchange.

### 2. Variational Algorithms (VQE & QAOA)
Hybrid loops where a classical optimizer tunes parameters on a quantum circuit to find ground states or solve combinatorial problems.

### 3. Fault Tolerance
Basic error correction demonstrates the use of redundancy (repetition codes) and syndrome measurement to protect quantum information.

---

*“Quantum mechanics: Small things behave badly.”* — Modern Physics Motto
