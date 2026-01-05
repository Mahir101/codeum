"""
Complete Collection of Quantum Algorithms - Quick Reference
All major quantum algorithms with complexity analysis
"""

# ============================================================================
# 1. SEARCH & DATABASE ALGORITHMS
# ============================================================================

algorithms = {
    "Grover's Algorithm": {
        "complexity": "O(√N)",
        "classical": "O(N)",
        "speedup": "Quadratic",
        "use_cases": [
            "Unsorted database search",
            "Breaking symmetric encryption (AES)",
            "SAT solving",
            "Collision finding"
        ],
        "implementation": "Grovers_Algorithm.py"
    },
    
    # ========================================================================
    # 2. FACTORIZATION & NUMBER THEORY
    # ========================================================================
    
    "Shor's Algorithm": {
        "complexity": "O(n² log n log log n)",
        "classical": "O(exp(n^(1/3)))",
        "speedup": "Exponential",
        "use_cases": [
            "Integer factorization",
            "Breaking RSA encryption",
            "Discrete logarithm",
            "Order finding"
        ],
        "components": ["QFT", "Period Finding", "Continued Fractions"]
    },
    
    # ========================================================================
    # 3. QUANTUM FOURIER TRANSFORM
    # ========================================================================
    
    "Quantum Fourier Transform": {
        "complexity": "O(n²) gates",
        "classical": "O(n·2^n)",
        "speedup": "Exponential",
        "use_cases": [
            "Core of Shor's algorithm",
            "Phase estimation",
            "Hidden subgroup problem",
            "Quantum simulation"
        ],
        "implementation": "Quantum_Fourier_Transform.py"
    },
    
    # ========================================================================
    # 4. OPTIMIZATION ALGORITHMS
    # ========================================================================
    
    "VQE (Variational Quantum Eigensolver)": {
        "complexity": "Depends on ansatz",
        "type": "Hybrid quantum-classical",
        "use_cases": [
            "Molecular energy calculation",
            "Drug discovery",
            "Materials science",
            "Electronic structure problems"
        ],
        "implementation": "VQE_Variational_Quantum_Eigensolver.py"
    },
    
    "QAOA (Quantum Approximate Optimization)": {
        "complexity": "Depends on depth p",
        "type": "Hybrid quantum-classical",
        "use_cases": [
            "MaxCut problem",
            "Traveling salesman",
            "Portfolio optimization",
            "Vehicle routing"
        ]
    },
    
    # ========================================================================
    # 5. PHASE ESTIMATION & EIGENVALUE PROBLEMS
    # ========================================================================
    
    "Quantum Phase Estimation": {
        "complexity": "O(n²) for n-bit precision",
        "use_cases": [
            "Finding eigenvalues of unitary operators",
            "Quantum chemistry calculations",
            "Machine learning (quantum PCA)",
            "Core subroutine for many algorithms"
        ]
    },
    
    " HHL Algorithm (Linear Systems)": {
        "complexity": "O(log N) vs O(N)",
        "use_cases": [
            "Solving linear equations Ax=b",
            "Machine learning (quantum least squares)",
            "Data fitting",
            "Optimization problems"
        ],
        "caveat": "Exponential speedup but output is quantum state"
    },
    
    # ========================================================================
    # 6. ORACLE-BASED ALGORITHMS
    # ========================================================================
    
    "Deutsch-Jozsa Algorithm": {
        "complexity": "O(1) query",
        "classical": "O(2^(n-1)) worst case",
        "use_cases": [
            "Determining if function is constant or balanced",
            "Theoretical demonstration of quantum advantage",
            "First quantum algorithm with speedup"
        ]
    },
    
    "Simon's Algorithm": {
        "complexity": "O(n) queries",
        "classical": "O(2^(n/2)) queries",
        "use_cases": [
            "Period finding",
            "Breaking certain cryptographic schemes",
            "Precursor to Shor's algorithm"
        ]
    },
    
    "Bernstein-Vazirani Algorithm": {
        "complexity": "O(1) query",
        "classical": "O(n) queries",
        "use_cases": [
            "Finding hidden binary string",
            "Demonstrating quantum parallelism",
            "Oracle separation problems"
        ]
    },
    
    # ========================================================================
    # 7. AMPLITUDE AMPLIFICATION & ESTIMATION
    # ========================================================================
    
    "Amplitude Amplification": {
        "description": "Generalization of Grover's algorithm",
        "use_cases": [
            "Boosting success probability of quantum algorithms",
            "Quantum counting",
            "Collision resistance"
        ]
    },
    
    "Amplitude Estimation": {
        "complexity": "O(1/ε) for accuracy ε",
        "use_cases": [
            "Monte Carlo estimation (quadratic speedup)",
            "Financial modeling",
            "Risk analysis",
            "Option pricing"
        ]
    },
    
    # ========================================================================
    # 8. QUANTUM SIMULATION
    # ========================================================================
    
    "Quantum Simulation (Hamiltonian Simulation)": {
        "complexity": "Polynomial vs exponential classical",
        "use_cases": [
            "Simulating quantum systems",
            "Condensed matter physics",
            "Many-body quantum dynamics",
            "Drug discovery (molecular dynamics)"
        ],
        "techniques": ["Trotterization", "Qubitization", "Linear combinations of unitaries"]
    },
    
    "Variational Quantum Simulation": {
        "use_cases": [
            "Simulating time evolution",
            "Imaginary time evolution",
            "Ground state preparation"
        ]
    },
    
    # ========================================================================
    # 9. QUANTUM MACHINE LEARNING
    # ========================================================================
    
    "Quantum Support Vector Machine": {
        "speedup": "Exponential in feature space dimension",
        "use_cases": [
            "Classification with quantum feature maps",
            "Kernel methods",
            "Pattern recognition"
        ]
    },
    
    "Quantum Neural Networks": {
        "type": "Variational quantum circuits",
        "use_cases": [
            "Quantum classification",
            "Generative models (qGANs)",
            "Reinforcement learning"
        ]
    },
    
    "Quantum Principal Component Analysis": {
        "complexity": "O(log(MN)) vs O(MN²)",
        "use_cases": [
            "Dimensionality reduction",
            "Data analysis",
            "Feature extraction"
        ]
    },
    
    # ========================================================================
    # 10. QUANTUM COMMUNICATION & CRYPTOGRAPHY
    # ========================================================================
    
    "Quantum Teleportation": {
        "use_cases": [
            "Transmitting quantum states",
            "Quantum networks",
            "Distributed quantum computing",
            "Quantum internet"
        ]
    },
    
    "BB84 Quantum Key Distribution": {
        "security": "Information-theoretically secure",
        "use_cases": [
            "Secure communication",
            "Cryptographic key exchange",
            "Banking security",
            "Government communications"
        ]
    },
    
    "Quantum Secret Sharing": {
        "use_cases": [
            "Distributed trust",
            "Secure multiparty computation",
            "Threshold cryptography"
        ]
    },
    
    # ========================================================================
    # 11. QUANTUM WALKS
    # ========================================================================
    
    "Quantum Walk Algorithms": {
        "speedup": "Quadratic for many problems",
        "use_cases": [
            "Element distinctness",
            "Triangle finding",
            "Graph problems",
            "Spatial search"
        ]
    },
    
    # ========================================================================
    # 12. QUANTUM ERROR CORRECTION
    # ========================================================================
    
    "Shor Code": {
        "description": "First quantum error correction code (9 qubits)",
        "protects": "Against bit flip and phase flip errors"
    },
    
    "Steane Code": {
        "description": "7-qubit CSS code",
        "advantage": "Transversal gates"
    },
    
    "Surface Code": {
        "description": "Topological code (most practical)",
        "use_cases": [
            "Fault-tolerant quantum computing",
            "Google, IBM quantum computers",
            "High threshold for errors"
        ]
    },
    
    # ========================================================================
    # 13. SPECIALIZED ALGORITHMS
    # ========================================================================
    
    "Quantum Annealing": {
        "hardware": "D-Wave quantum annealers",
        "use_cases": [
            "Optimization problems",
            "QUBO/Ising models",
            "Sampling",
            "Machine learning training"
        ]
    },
    
    "Quantum Counting": {
        "description": "Counts solutions using Grover + QFT",
        "use_cases": [
            "Counting satisfying assignments",
            "#P problems",
            "Approximate counting"
        ]
    },
    
    "Quantum Sampling": {
        "use_cases": [
            "Demonstrating quantum supremacy (Google 2019)",
            "Random circuit sampling",
            "Boson sampling"
        ]
    }
}

# ============================================================================
# PRINT SUMMARY
# ============================================================================

if __name__ == "__main__":
    print("="*70)
    print(" "*15 + "QUANTUM ALGORITHMS COMPENDIUM")
    print("="*70)
    
    categories = {
        "Search & Database": ["Grover's Algorithm"],
        "Factorization & Number Theory": ["Shor's Algorithm"],
        "Transforms": ["Quantum Fourier Transform"],
        "Optimization": ["VQE (Variational Quantum Eigensolver)", 
                        "QAOA (Quantum Approximate Optimization)"],
        "Phase & Eigenvalue": ["Quantum Phase Estimation", 
                              "HHL Algorithm (Linear Systems)"],
        "Oracle-Based": ["Deutsch-Jozsa Algorithm", "Simon's Algorithm", 
                        "Bernstein-Vazirani Algorithm"],
        "Amplitude Methods": ["Amplitude Amplification", "Amplitude Estimation"],
        "Simulation": ["Quantum Simulation (Hamiltonian Simulation)", 
                      "Variational Quantum Simulation"],
        "Machine Learning": ["Quantum Support Vector Machine", 
                           "Quantum Neural Networks", 
                           "Quantum Principal Component Analysis"],
        "Communication & Crypto": ["Quantum Teleportation", 
                                  "BB84 Quantum Key Distribution", 
                                  "Quantum Secret Sharing"],
        "Walks": ["Quantum Walk Algorithms"],
        "Error Correction": ["Shor Code", "Steane Code", "Surface Code"],
        "Specialized": ["Quantum Annealing", "Quantum Counting", "Quantum Sampling"]
    }
    
    total_algorithms = 0
    for category, alg_list in categories.items():
        print(f"\n{category} ({len(alg_list)} algorithms)")
        print("-" * 70)
        total_algorithms += len(alg_list)
        
        for alg_name in alg_list:
            if alg_name in algorithms:
                alg = algorithms[alg_name]
                print(f"  • {alg_name}")
                
                if "complexity" in alg:
                    print(f"    Quantum: {alg['complexity']}")
                if "classical" in alg:
                    print(f"    Classical: {alg['classical']}")
                if "speedup" in alg:
                    print(f"    Speedup: {alg['speedup']}")
                
                if "use_cases" in alg:
                    print(f"    Use cases: {', '.join(alg['use_cases'][:2])}")
                
                print()
    
    print("="*70)
    print(f"Total Quantum Algorithms: {total_algorithms}")
    print("="*70)
    
    print("\nImplementation Status:")
    print("  ✓ Grover's Algorithm")
    print("  ✓ Quantum Fourier Transform")
    print("  ✓ Variational Quantum Eigensolver (VQE)")
    print("  📝 Shor's Algorithm (coming soon)")
    print("  📝 QAOA (coming soon)")
    print("  📝 Quantum Phase Estimation (coming soon)")
    
    print("\n✅ Quantum algorithms reference complete!")
