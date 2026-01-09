# G-QBME: Gravitational Quantum Biopolymer Morphogenesis Engine

## Overview
G-QBME is a completely unprecedented computational framework that predicts DNA and protein folding by incorporating **General Relativity** and **Quantum Coherence**. 

Traditional molecular biology treats gravity as negligible. G-QBME hypothesizes that the local spacetime metric $g_{\mu\nu}$ and the resulting gravitational potential $\Phi$ introduce a "Berry Phase" correction to the electronic state of base-stacking, leading to macroscopic geometric shifts (torsion) in the double helix.

## Theoretical Components

### 1. Relativistic Molecular Geometry
The engine treats the double helix as a manifold where the helical pitch $P$ is a function of the Ricci curvature $R$:
$$ P(g) = P_0 + \gamma \int R_{\mu\nu} u^\mu u^\nu d\tau $$

### 2. The Schrödinger-Newton (SN) Coupling
We solve a modified SN equation for the electronic cloud density $\rho_e$:
$$ i\hbar \frac{\partial \psi}{\partial t} = -\frac{\hbar^2}{2m}\nabla^2\psi + V_{EM}\psi + m\Phi\psi $$
where $\nabla^2 \Phi = 4\pi G (\rho_{atoms} + \rho_e)$.

## Architecture
- **Rust Engine (g_qbme):** Handles high-performance mass density mapping and gravitational potential summation using Fast Multipole inspirations.
- **Quantum Kernel (Python):** Uses matrix-based eigensolvers (simulating VQE) to determine electronic energy levels under gravitational flux.
- **Unified Propagator (Streamlit):** A visual interface for configuring spacetime conditions (e.g., Earth vs. Neutron Star) and observing structural divergence.

## How to Run

### 1. Build the Rust Engine
```bash
cd G-QBME
cargo build --release
```

### 2. Run the Visualization
```bash
streamlit run src/prediction_viz.py
```

## Mashup Formulas Implemented
- **Levitt-Warshel Geometry:** Base-pair coordinate mapping.
- **Linearized Einstein Metric:** $ds^2 = -(1+2\Phi)dt^2 + (1-2\Phi)d\mathbf{x}^2$.
- **Hamiltonian Perturbation:** $H' = H_0 + m\Phi I$.
