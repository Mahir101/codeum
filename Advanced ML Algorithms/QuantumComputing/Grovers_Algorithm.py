"""
Grover's Search Algorithm
Quantum algorithm for searching unsorted database in O(√N) time
Using Qiskit framework
"""

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit import Aer, execute
from qiskit.visualization import plot_histogram
import numpy as np
import math


def grover_oracle(circuit, qubits, target):
    """
    Oracle that marks the target state
    Flips the phase of |target⟩
    """
    n = len(qubits)
    
    # Convert target to binary and flip qubits that should be 0
    target_bits = format(target, f'0{n}b')
    
    for i, bit in enumerate(target_bits):
        if bit == '0':
            circuit.x(qubits[i])
    
    # Multi-controlled Z gate
    if n == 1:
        circuit.z(qubits[0])
    elif n == 2:
        circuit.cz(qubits[0], qubits[1])
    else:
        # Multi-controlled Z using ancilla
        circuit.h(qubits[-1])
        circuit.mcx(qubits[:-1], qubits[-1])
        circuit.h(qubits[-1])
    
    # Flip back
    for i, bit in enumerate(target_bits):
        if bit == '0':
            circuit.x(qubits[i])


def grover_diffusion(circuit, qubits):
    """
    Diffusion operator (inversion about average)
    2|s⟩⟨s| - I where |s⟩ is uniform superposition
    """
    n = len(qubits)
    
    # H gates
    for qubit in qubits:
        circuit.h(qubit)
    
    # X gates
    for qubit in qubits:
        circuit.x(qubit)
    
    # Multi-controlled Z
    if n == 1:
        circuit.z(qubits[0])
    elif n == 2:
        circuit.cz(qubits[0], qubits[1])
    else:
        circuit.h(qubits[-1])
        circuit.mcx(qubits[:-1], qubits[-1])
        circuit.h(qubits[-1])
    
    # X gates
    for qubit in qubits:
        circuit.x(qubit)
    
    # H gates
    for qubit in qubits:
        circuit.h(qubit)


def grovers_algorithm(n_qubits, target):
    """
    Complete Grover's algorithm
    
    Args:
        n_qubits: Number of qubits (searches 2^n items)
        target: Target item to find (integer)
    
    Returns:
        QuantumCircuit: The complete circuit
    """
    # Create quantum circuit
    qr = QuantumRegister(n_qubits, 'q')
    cr = ClassicalRegister(n_qubits, 'c')
    circuit = QuantumCircuit(qr, cr)
    
    # Initialize to uniform superposition
    for qubit in qr:
        circuit.h(qubit)
    
    # Optimal number of iterations: π/4 * √N
    N = 2 ** n_qubits
    iterations = int(math.pi / 4 * math.sqrt(N))
    
    # Grover iterations
    for _ in range(iterations):
        # Oracle
        grover_oracle(circuit, qr, target)
        
        # Diffusion
        grover_diffusion(circuit, qr)
    
    # Measure
    circuit.measure(qr, cr)
    
    return circuit


def run_grovers_search(n_qubits, target, shots=1024):
    """
    Run Grover's algorithm and return results
    """
    circuit = grovers_algorithm(n_qubits, target)
    
    # Execute on simulator
    simulator = Aer.get_backend('qasm_simulator')
    job = execute(circuit, simulator, shots=shots)
    result = job.result()
    counts = result.get_counts(circuit)
    
    return counts, circuit


# Example usage and tests
if __name__ == "__main__":
    print("="*60)
    print("Grover's Search Algorithm - Quantum Database Search")
    print("="*60)
    
    # Test 1: Search in 4 items (2 qubits)
    print("\nTest 1: Searching 4 items for target=2")
    print("-" * 40)
    
    n_qubits = 2
    target = 2
    
    counts, circuit = run_grovers_search(n_qubits, target, shots=1000)
    
    print(f"Search space size: {2**n_qubits}")
    print(f"Target: {target} (binary: {format(target, f'0{n_qubits}b')})")
    print(f"Optimal iterations: {int(math.pi/4 * math.sqrt(2**n_qubits))}")
    print(f"\nMeasurement results:")
    
    for bitstring, count in sorted(counts.items(), key=lambda x: -x[1]):
        percentage = count / 1000 * 100
        print(f"  {bitstring}: {count:4d} times ({percentage:5.1f}%)")
    
    target_bitstring = format(target, f'0{n_qubits}b')
    success_rate = counts.get(target_bitstring, 0) / 1000 * 100
    print(f"\n✓ Success rate: {success_rate:.1f}%")
    
    # Test 2: Search in 8 items (3 qubits)
    print("\n" + "="*60)
    print("Test 2: Searching 8 items for target=5")
    print("-" * 40)
    
    n_qubits = 3
    target = 5
    
    counts, circuit = run_grovers_search(n_qubits, target, shots=1000)
    
    print(f"Search space size: {2**n_qubits}")
    print(f"Target: {target} (binary: {format(target, f'0{n_qubits}b')})")
    print(f"Optimal iterations: {int(math.pi/4 * math.sqrt(2**n_qubits))}")
    print(f"\nMeasurement results (top 3):")
    
    for bitstring, count in sorted(counts.items(), key=lambda x: -x[1])[:3]:
        percentage = count / 1000 * 100
        print(f"  {bitstring}: {count:4d} times ({percentage:5.1f}%)")
    
    target_bitstring = format(target, f'0{n_qubits}b')
    success_rate = counts.get(target_bitstring, 0) / 1000 * 100
    print(f"\n✓ Success rate: {success_rate:.1f}%")
    
    # Complexity comparison
    print("\n" + "="*60)
    print("Complexity Comparison")
    print("="*60)
    print(f"Classical search: O(N) = O({2**n_qubits})")
    print(f"Grover's search: O(√N) = O({int(math.sqrt(2**n_qubits))})")
    print(f"Speedup: {2**n_qubits / math.sqrt(2**n_qubits):.1f}x")
    
    print("\n" + "="*60)
    print("Real-World Applications:")
    print("="*60)
    print("• Database search (quadratic speedup)")
    print("• Breaking symmetric encryption (brute force)")
    print("• SAT solving")
    print("• Constraint satisfaction problems")
    print("• Quantum machine learning (k-means)")
    
    print("\n✅ Grover's algorithm demonstration complete!")
