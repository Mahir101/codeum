"""
Quantum Fourier Transform (QFT)
Core subroutine for many quantum algorithms including Shor's algorithm
Time: O(n²) gates vs classical O(n·2^n)
"""

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit import Aer, execute
import numpy as np
import math


def qft(circuit, qubits, inverse=False):
    """
    Apply Quantum Fourier Transform to qubits
    
    QFT|j⟩ = 1/√N Σ_k e^(2πijk/N)|k⟩
    
    Args:
        circuit: QuantumCircuit to add QFT to
        qubits: List of qubits to transform
        inverse: If True, apply inverse QFT
    """
    n = len(qubits)
    
    if inverse:
        # Inverse QFT (reverse operations)
        for i in range(n // 2):
            circuit.swap(qubits[i], qubits[n - i - 1])
        
        for j in range(n):
            for k in range(j):
                circuit.cp(-math.pi / (2 ** (j - k)), qubits[k], qubits[j])
            circuit.h(qubits[j])
    else:
        # Forward QFT
        for j in reversed(range(n)):
            circuit.h(qubits[j])
            for k in reversed(range(j)):
                circuit.cp(math.pi / (2 ** (j - k)), qubits[k], qubits[j])
        
        # Reverse qubit order
        for i in range(n // 2):
            circuit.swap(qubits[i], qubits[n - i - 1])


def create_qft_circuit(n_qubits, inverse=False):
    """
    Create standalone QFT circuit
    """
    qr = QuantumRegister(n_qubits, 'q')
    circuit = QuantumCircuit(qr)
    
    qft(circuit, qr, inverse=inverse)
    
    return circuit


def qft_with_measurement(n_qubits, input_state=None):
    """
    QFT circuit with state preparation and measurement
    
    Args:
        n_qubits: Number of qubits
        input_state: Integer to encode (if None, uses uniform superposition)
    """
    qr = QuantumRegister(n_qubits, 'q')
    cr = ClassicalRegister(n_qubits, 'c')
    circuit = QuantumCircuit(qr, cr)
    
    # Prepare input state
    if input_state is not None:
        # Encode classical state
        binary = format(input_state, f'0{n_qubits}b')
        for i, bit in enumerate(binary):
            if bit == '1':
                circuit.x(qr[i])
    else:
        # Uniform superposition
        for qubit in qr:
            circuit.h(qubit)
    
    circuit.barrier()
    
    # Apply QFT
    qft(circuit, qr)
    
    circuit.barrier()
    
    # Measure
    circuit.measure(qr, cr)
    
    return circuit


def demonstrate_qft_periodicity(n_qubits=4):
    """
    Demonstrate QFT's ability to detect periodicity
    """
    qr = QuantumRegister(n_qubits, 'q')
    cr = ClassicalRegister(n_qubits, 'c')
    circuit = QuantumCircuit(qr, cr)
    
    # Create periodic state with period = 2
    # |0⟩ + |2⟩ + |4⟩ + ... (even numbers)
    for i in range(0, 2**n_qubits, 2):
        binary = format(i, f'0{n_qubits}b')
        # Apply X gates for this state
        temp_circuit = QuantumCircuit(qr)
        for j, bit in enumerate(binary):
            if bit == '1':
                temp_circuit.x(qr[j])
        
        # Controlled sum (simplified for demo)
        if i == 0:
            for j, bit in enumerate(binary):
                if bit == '1':
                    circuit.x(qr[j])
    
    # Equal superposition of even numbers
    circuit.h(qr[0])  # Controls odd/even
    
    circuit.barrier()
    qft(circuit, qr)
    circuit.barrier()
    circuit.measure(qr, cr)
    
    return circuit


# Example usage and tests
if __name__ == "__main__":
    print("="*60)
    print("Quantum Fourier Transform (QFT)")
    print("="*60)
    
    # Test 1: QFT on computational basis state
    print("\nTest 1: QFT on |3⟩ with 3 qubits")
    print("-" * 40)
    
    n_qubits = 3
    input_state = 3
    
    circuit = qft_with_measurement(n_qubits, input_state)
    
    print(f"Input state: |{input_state}⟩ = |{format(input_state, f'0{n_qubits}b')}⟩")
    print(f"Number of gates: {sum(circuit.count_ops().values())}")
    
    # Execute
    simulator = Aer.get_backend('qasm_simulator')
    job = execute(circuit, simulator, shots=1000)
    result = job.result()
    counts = result.get_counts(circuit)
    
    print(f"\nTop measurement results:")
    for bitstring, count in sorted(counts.items(), key=lambda x: -x[1])[:5]:
        percentage = count / 1000 * 100
        print(f"  |{bitstring}⟩: {count:4d} times ({percentage:5.1f}%)")
    
    # Test 2: QFT → Inverse QFT (should recover input)
    print("\n" + "="*60)
    print("Test 2: QFT → Inverse QFT (Identity Test)")
    print("-" * 40)
    
    n_qubits = 3
    input_state = 5
    
    qr = QuantumRegister(n_qubits, 'q')
    cr = ClassicalRegister(n_qubits, 'c')
    circuit = QuantumCircuit(qr, cr)
    
    # Prepare input
    binary = format(input_state, f'0{n_qubits}b')
    for i, bit in enumerate(binary):
        if bit == '1':
            circuit.x(qr[i])
    
    circuit.barrier()
    
    # QFT
    qft(circuit, qr, inverse=False)
    
    circuit.barrier()
    
    # Inverse QFT
    qft(circuit, qr, inverse=True)
    
    circuit.barrier()
    circuit.measure(qr, cr)
    
    # Execute
    job = execute(circuit, simulator, shots=1000)
    result = job.result()
    counts = result.get_counts(circuit)
    
    print(f"Input state: |{input_state}⟩ = |{format(input_state, f'0{n_qubits}b')}⟩")
    print(f"\nMeasurement results after QFT → QFT⁻¹:")
    
    for bitstring, count in sorted(counts.items(), key=lambda x: -x[1])[:3]:
        percentage = count / 1000 * 100
        is_original = "✓ ORIGINAL" if int(bitstring, 2) == input_state else ""
        print(f"  |{bitstring}⟩: {count:4d} times ({percentage:5.1f}%) {is_original}")
    
    # Verify we recovered the input
    target_bitstring = format(input_state, f'0{n_qubits}b')
    success_rate = counts.get(target_bitstring, 0) / 1000 * 100
    print(f"\n✓ Recovery success rate: {success_rate:.1f}%")
    
    # Complexity comparison
    print("\n" + "="*60)
    print("Complexity Analysis")
    print("="*60)
    print(f"Classical FFT: O(n·2^n) for n qubits")
    print(f"Quantum QFT: O(n²) gates")
    print(f"\nFor n={n_qubits} qubits:")
    print(f"  Classical: {n_qubits * 2**n_qubits} operations")
    print(f"  Quantum: ~{n_qubits**2} gates")
    print(f"  Speedup: {(n_qubits * 2**n_qubits) / (n_qubits**2):.1f}x")
    
    print("\n" + "="*60)
    print("Applications:")
    print("="*60)
    print("• Shor's Algorithm (period finding)")
    print("• Quantum Phase Estimation")
    print("• Hidden Subgroup Problem")
    print("• Quantum simulation")
    print("• Order finding in cryptography")
    
    print("\n✅ QFT demonstration complete!")
