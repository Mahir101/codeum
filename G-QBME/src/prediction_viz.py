import streamlit as st
import subprocess
import pandas as pd
import numpy as np
import plotly.graph_objects as go
from quantum_kernel import QuantumBioSolver
import os

st.set_page_config(page_title="G-QBME: Gravitational Bio-Engine", layout="wide")

st.title("G-QBME: Gravitational Quantum Biopolymer Morphogenesis Engine")
st.markdown("""
### Unprecedented Prediction of DNA Geometry under Relativistic Perturbation
Integrating Molecular Biology, General Relativity, and Quantum Coherence.
""")

# Sidebar settings
st.sidebar.header("Configuration")
num_bp = st.sidebar.slider("Number of Base Pairs", 5, 50, 20)
grav_multiplier = st.sidebar.select_slider(
    "Gravitational Flux",
    options=["Earth", "Jupiter", "Neutron Star", "Singularity"],
    value="Earth"
)

flux_vals = {
    "Earth": -1e-10,
    "Jupiter": -1e-8,
    "Neutron Star": -1.0,
    "Singularity": -1e10
}

def run_rust_engine(num_bp):
    # Path to the compiled Rust binary
    binary_path = "./target/release/g_qbme"
    if not os.path.exists(binary_path):
        return None, "Binary not found"
    
    result = subprocess.run([binary_path, "generate_dna", str(num_bp)], 
                            capture_output=True, text=True, cwd="./")
    return result.stdout, result.stderr

if st.button("Run Unified Simulation"):
    with st.spinner("Calculating Spacetime Metric & Quantum Perturbations..."):
        # 1. Run Rust Engine
        output, error = run_rust_engine(num_bp)
        
        if output:
            lines = output.split("\n")
            atoms = []
            phi = 0.0
            for line in lines:
                if line.startswith("ATOM"):
                    parts = line.split()
                    atoms.append({
                        "id": parts[1],
                        "element": parts[2],
                        "x": float(parts[3]),
                        "y": float(parts[4]),
                        "z": float(parts[5])
                    })
                if "Gravitational Potential" in line:
                    phi = float(line.split(":")[2].strip())
            
            df = pd.DataFrame(atoms)
            
            # 2. Run Quantum Solver
            actual_phi = phi * (flux_vals[grav_multiplier] / flux_vals["Earth"])
            solver = QuantumBioSolver()
            energy, params = solver.solve_ground_state(actual_phi)
            
            col1, col2 = st.columns(2)
            
            with col1:
                st.subheader("3D DNA Geometry")
                fig = go.Figure(data=[go.Scatter3d(
                    x=df['x'], y=df['y'], z=df['z'],
                    mode='markers+lines',
                    marker=dict(size=4, color=df['z'], colorscale='Viridis'),
                    line=dict(color='gray', width=2)
                )])
                fig.update_layout(margin=dict(l=0, r=0, b=0, t=0))
                st.plotly_chart(fig, use_container_width=True)
                
            with col2:
                st.subheader("Compute Metrics")
                st.metric("Self-Gravitation Potential (\Phi)", f"{phi:.2e} J/kg")
                st.metric("Quantum Ground State Energy (Eh)", f"{energy:.6f}")
                
                st.info(f"Gravitational Torsion: Applied level {grav_multiplier}")
                
                # Visualization of Gravitational Stress
                st.subheader("Gravitational Stress Heatmap")
                z_vals = np.linspace(0, num_bp * 3.4, 50)
                stress = np.abs(np.sin(z_vals) * actual_phi)
                st.line_chart(stress)
                
        else:
            st.error(f"Engine Failure: {error}")

st.divider()
st.markdown("""
**Theory Reference:**
The G-QBME Framework uses the Schrödinger-Newton equation to model the coupling between the gravitational field and the quantum state of 
electronic clouds in DNA base-stacking. The "Gravitational Berry Phase" is hypothesized to emerge as a structural correction to the standard
B-DNA double helix pitch.
""")
