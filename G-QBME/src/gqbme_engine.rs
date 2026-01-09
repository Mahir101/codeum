use std::collections::HashMap;

/// Represents a 3D coordinate in space
#[derive(Debug, Clone, Copy)]
pub struct Vector3 {
    pub x: f64,
    pub y: f64,
    pub z: f64,
}

impl Vector3 {
    pub fn new(x: f64, y: f64, z: f64) -> Self {
        Self { x, y, z }
    }

    pub fn dist(&self, other: &Vector3) -> f64 {
        ((self.x - other.x).powi(2) + (self.y - other.y).powi(2) + (self.z - other.z).powi(2)).sqrt()
    }
}

/// Represents an atom in a biomolecule
#[derive(Debug, Clone)]
pub struct Atom {
    pub element: String,
    pub position: Vector3,
    pub mass: f64, // atomic mass in Daltons
}

/// A biomolecule (DNA or Protein)
#[derive(Debug, Clone)]
pub struct Biomolecule {
    pub atoms: Vec<Atom>,
}

impl Biomolecule {
    pub fn new() -> Self {
        Self { atoms: Vec::new() }
    }

    pub fn add_atom(&mut self, element: String, x: f64, y: f64, z: f64, mass: f64) {
        self.atoms.push(Atom {
            element,
            position: Vector3::new(x, y, z),
            mass,
        });
    }

    /// Calculates the Center of Mass
    pub fn center_of_mass(&self) -> Vector3 {
        let total_mass: f64 = self.atoms.iter().map(|a| a.mass).sum();
        let mut com = Vector3::new(0.0, 0.0, 0.0);
        for atom in &self.atoms {
            com.x += atom.position.x * atom.mass;
            com.y += atom.position.y * atom.mass;
            com.z += atom.position.z * atom.mass;
        }
        Vector3::new(com.x / total_mass, com.y / total_mass, com.z / total_mass)
    }
}

/// A voxel grid for mass density mapping \rho(\mathbf{r})
#[derive(Debug)]
pub struct MassDensityGrid {
    pub origin: Vector3,
    pub resolution: f64, // size of one voxel in Angstroms
    pub dimensions: (usize, usize, usize),
    pub data: Vec<f64>, // linearized 3D grid
}

impl MassDensityGrid {
    pub fn new(origin: Vector3, resolution: f64, dims: (usize, usize, usize)) -> Self {
        let size = dims.0 * dims.1 * dims.2;
        Self {
            origin,
            resolution,
            dimensions: dims,
            data: vec![0.0; size],
        }
    }

    fn get_index(&self, x: usize, y: usize, z: usize) -> usize {
        x * self.dimensions.1 * self.dimensions.2 + y * self.dimensions.2 + z
    }

    /// Maps atoms into the density grid
    pub fn map_biomolecule(&mut self, molecule: &Biomolecule) {
        for atom in &molecule.atoms {
            let rel_x = (atom.position.x - self.origin.x) / self.resolution;
            let rel_y = (atom.position.y - self.origin.y) / self.resolution;
            let rel_z = (atom.position.z - self.origin.z) / self.resolution;

            let ix = rel_x.round() as i32;
            let iy = rel_y.round() as i32;
            let iz = rel_z.round() as i32;

            if ix >= 0 && ix < self.dimensions.0 as i32 &&
               iy >= 0 && iy < self.dimensions.1 as i32 &&
               iz >= 0 && iz < self.dimensions.2 as i32 {
                let idx = self.get_index(ix as usize, iy as usize, iz as usize);
                self.data[idx] += atom.mass;
            }
        }
    }
}

/// DNA Double Helix Generator (Unprecedented Geometry)
pub fn generate_dna_helix(num_base_pairs: usize, radius: f64, pitch: f64) -> Biomolecule {
    let mut dna = Biomolecule::new();
    let bp_rise = pitch / 10.5; // average rise per base pair
    let angle_step = 2.0 * std::f64::consts::PI / 10.5;

    for i in 0..num_base_pairs {
        let z = i as f64 * bp_rise;
        let angle = i as f64 * angle_step;

        // Strand 1 (Phosphate placeholder)
        dna.add_atom("P".to_string(), radius * angle.cos(), radius * angle.sin(), z, 30.97);
        // Strand 2 (Phosphate placeholder, shifted by PI)
        dna.add_atom("P".to_string(), radius * (angle + std::f64::consts::PI).cos(), radius * (angle + std::f64::consts::PI).sin(), z, 30.97);
    }
    dna
}

/// CONSTANTS
const G_CONSTANT: f64 = 6.67430e-11; // m^3 kg^-1 s^-2
const DALTON_TO_KG: f64 = 1.660539e-27;

/// Relativistic Perturbation Module
pub struct RelativisticSolver;

impl RelativisticSolver {
    /// Calculates the Gravitational Potential at a point r
    /// \Phi(r) = - \sum (G * m_i / |r - r_i|)
    pub fn calculate_potential(position: &Vector3, grid: &MassDensityGrid) -> f64 {
        let mut potential = 0.0;
        
        for (idx, &mass) in grid.data.iter().enumerate() {
            if mass <= 0.0 { continue; }
            
            // Convert index back to grid coordinates
            let x = idx / (grid.dimensions.1 * grid.dimensions.2);
            let y = (idx / grid.dimensions.2) % grid.dimensions.1;
            let z = idx % grid.dimensions.2;
            
            let voxel_pos = Vector3::new(
                grid.origin.x + x as f64 * grid.resolution,
                grid.origin.y + y as f64 * grid.resolution,
                grid.origin.z + z as f64 * grid.resolution,
            );
            
            let r = position.dist(&voxel_pos) * 1e-10; // Convert Angstroms to Meters
            if r > 0.0 {
                potential -= G_CONSTANT * (mass * DALTON_TO_KG) / r;
            }
        }
        potential
    }

    /// Calculates "Gravitational Torsion" effect on DNA twist
    /// \Omega = \Omega_0 + \alpha * \Phi
    pub fn compute_metric_torsion(base_twist: f64, potential: f64) -> f64 {
        let alpha = 1.0e-30; // Hypothesized "Gravi-Genetic Coupling Constant"
        base_twist + alpha * potential
    }
}
