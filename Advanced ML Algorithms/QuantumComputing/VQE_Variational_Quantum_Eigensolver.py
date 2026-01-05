"""
Variational Quantum Eigensolver (VQE)
Hybrid quantum-classical algorithm for finding ground state energies
Uses on NISQ (Noisy Intermediate-Scale Quantum) devices
"""

from qiskit import QuantumCircuit, QuantumRegister, Aer, execute
from qiskit.circuit import Parameter
from qiskit.quantum_info import Pauli
import numpy as np
from scipy.optimize import minimize


class VQE:
    """
    Variational Quantum Eigensolver implementation
    """
    def __init__(self, hamiltonian, n_qubits, ansatz_depth=2):
        """
        Args:
            hamiltonian: Dict mapping Pauli strings to coefficients
            n_qubits: Number of qubits
            ansatz_depth: Depth of variational circuit
        """
        self.hamiltonian = hamiltonian
        self.n_qubits = n_qubits
        self.ansatz_depth = ansatz_depth
        self.backend = Aer.get_backend('qasm_simulator')
    
    def create_ansatz(self, parameters):
        """
        Create variational ansatz circuit (also called trial wavefunction)
        Using RY-RZ-CNOT layers (hardware-efficient ansatz)
        """
        qr = QuantumRegister(self.n_qubits, 'q')
        circuit = QuantumCircuit(qr)
        
        param_idx = 0
        
        for depth in range(self.ansatz_depth):
            # Layer of RY rotations
            for qubit in range(self.n_qubits):
                circuit.ry(parameters[param_idx], qr[qubit])
                param_idx += 1
            
            # Layer of RZ rotations
            for qubit in range(self.n_qubits):
                circuit.rz(parameters[param_idx], qr[qubit])
                param_idx += 1
            
            # Layer of CNOTs (entanglement)
            for qubit in range(self.n_qubits - 1):
                circuit.cx(qr[qubit], qr[qubit + 1])
        
        return circuit
    
    def measure_pauli_term(self, pauli_string, parameters):
        """
        Measure expectation value of a Pauli term
        
        Args:
            pauli_string: String like 'ZZ', 'XY', etc.
            parameters: Variational parameters
        """
        circuit = self.create_ansatz(parameters)
        qr = circuit.qregs[0]
        
        # Apply basis rotations
        for i, pauli in enumerate(pauli_string):
            if pauli == 'X':
                circuit.h(qr[i])
            elif pauli == 'Y':
                circuit.sdg(qr[i])
                circuit.h(qr[i])
            # Z basis is measurement basis (no rotation needed)
        
        # Measure
        circuit.measure_all()
        
        # Execute
        job = execute(circuit, self.backend, shots=1000)
        result = job.result()
        counts = result.get_counts(circuit)
        
        # Calculate expectation value
        expectation = 0
        for bitstring, count in counts.items():
            # Calculate parity
            parity = 1
            for i, char in enumerate(bitstring[::-1]):
                if pauli_string[i] != 'I' and char == '1':
                    parity *= -1
            
            expectation += parity * count / 1000
        
        return expectation
    
    def compute_energy(self, parameters):
        """
        Compute expectation value of Hamiltonian
        E = ⟨ψ(θ)|H|ψ(θ)⟩ = Σ_i c_i ⟨ψ(θ)|P_i|ψ(θ)⟩
        """
        energy = 0
        
        for pauli_string, coefficient in self.hamiltonian.items():
            if pauli_string == 'I' * self.n_qubits:
                # Identity term (constant)
                energy += coefficient
            else:
                expectation = self.measure_pauli_term(pauli_string, parameters)
                energy += coefficient * expectation
        
        return energy
    
    def optimize(self, initial_params=None, method='COBYLA'):
        """
        Run VQE optimization loop
        """
        # Random initial parameters if not provided
        n_params = 2 * self.n_qubits * self.ansatz_depth
        if initial_params is None:
            initial_params = np.random.rand(n_params) * 2 * np.pi
        
        # Track optimization
        self.energies = []
        
        def objective(params):
            energy = self.compute_energy(params)
            self.energies.append(energy)
            return energy
        
        # Classical optimization
        result = minimize(objective, initial_params, method=method,
                         options={'maxiter': 100})
        
        return result


def solve_h2_molecule():
    """
    Example: Find ground state energy of H2 molecule
    Using simplified Hamiltonian
    """
    print("="*60)
    print("VQE: H2 Molecule Ground State Energy")
    print("="*60)
    
    # H2 Hamiltonian (simplified, in units of Hartree)
    # Real H2 at equilibrium: E ≈ -1.137 Hartree
    hamiltonian = {
        'II': -1.0523,
        'ZI': 0.3979,
        'IZ': 0.3979,
        'ZZ': -0.0113,
        'XX': 0.1809
    }
    
    n_qubits = 2
    
    print(f"\nHamiltonian terms:")
    for term, coeff in hamiltonian.items():
        print(f"  {coeff:+.4f} * {term}")
    
    # Create VQE instance
    vqe = VQE(hamiltonian, n_qubits, ansatz_depth=2)
    
    print(f"\nRunning VQE optimization...")
    print(f"  Qubits: {n_qubits}")
    print(f"  Ansatz depth: {vqe.ansatz_depth}")
    print(f"  Parameters: {2 * n_qubits * vqe.ansatz_depth}")
    
    # Run optimization
    result = vqe.optimize()
    
    print(f"\n✓ Optimization complete!")
    print(f"\nResults:")
    print(f"  Ground state energy: {result.fun:.4f} Hartree")
    print(f"  Iterations: {len(vqe.energies)}")
    print(f"  Success: {result.success}")
    
    # Known ground state for comparison
    exact_energy = -1.1373  # Exact H2 ground state
    error = abs(result.fun - exact_energy)
    print(f"\nComparison with exact:")
    print(f"  Exact energy: {exact_energy:.4f} Hartree")
    print(f"  Error: {error:.4f} Hartree ({error/abs(exact_energy)*100:.2f}%)")
    
    # Show energy convergence
    print(f"\nEnergy convergence (first 10 iterations):")
    for i, e in enumerate(vqe.energies[:10]):
        print(f"  Iteration {i+1:2d}: {e:.4f} Hartree")
    
    return result


def solve_simple_hamiltonian():
    """
    Example: Solve simple 1-qubit Hamiltonian H = X + Z
    Ground state: (-√2)|+⟩, Energy = -√2 ≈ -1.414
    """
    print("\n" + "="*60)
    print("VQE: Simple 1-Qubit Hamiltonian H = X + Z")
    print("="*60)
    
    hamiltonian = {
        'X': 1.0,
        'Z': 1.0
    }
    
    n_qubits = 1
    
    print(f"\nHamiltonian: H = X + Z")
    print(f"Exact ground state energy: {-np.sqrt(2):.4f}")
    
    vqe = VQE(hamiltonian, n_qubits, ansatz_depth=1)
    
    print(f"\nRunning VQE...")
    result = vqE.optimize()
    
    print(f"\n✓ VQE Results:")
    print(f"  Energy: {result.fun:.4f}")
    print(f"  Error: {abs(result.fun + np.sqrt(2)):.4f}")
    
    return result


# Example usage
if __name__ == "__main__":
    # Solve H2 molecule
    h2_result = solve_h2_molecule()
    
    # Solve simple Hamiltonian
    # simple_result = solve_simple_hamiltonian()
    
    print("\n" + "="*60)
    print("VQE Applications:")
    print("="*60)
    print("• Drug discovery (molecular energy calculation)")
    print("• Materials science (predicting material properties)")
    print("• Quantum chemistry (electronic structure)")
    print("• Optimization problems (via QUBO encoding)")
    print("• Works on NISQ devices (no error correction needed)")
    
    print("\n" + "="*60)
    print("Why VQE on NISQ Devices:")
    print("="*60)
    print("• Short circuit depth (reduced decoherence)")
    print("• Variational (tolerates some noise)")
    print("• Quantum + Classical hybrid")
    print("• Flexible ansatz design")
    
    print("\n✅ VQE demonstration complete!")
