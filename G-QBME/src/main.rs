use g_qbme::gqbme_engine::{generate_dna_helix, MassDensityGrid, Vector3, RelativisticSolver};
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        println!("Usage: gqbme <command> [args]");
        return;
    }

    match args[1].as_str() {
        "generate_dna" => {
            let num_bp = args[2].parse::<usize>().unwrap_or(10);
            let dna = generate_dna_helix(num_bp, 10.0, 34.0);
            
            // Create a grid and map DNA
            let mut grid = MassDensityGrid::new(
                Vector3::new(-20.0, -20.0, 0.0),
                1.0,
                (40, 40, 100)
            );
            grid.map_biomolecule(&dna);
            
            // Calculate potential at the center
            let com = dna.center_of_mass();
            let phi = RelativisticSolver::calculate_potential(&com, &grid);
            
            println!("DNA Generated with {} base pairs", num_bp);
            println!("Center of Mass: {:?}, Gravitational Potential: {:.2e}", com, phi);
            
            // Output atom positions for visualization
            for (i, atom) in dna.atoms.iter().enumerate() {
                println!("ATOM {} {} {} {} {}", i, atom.element, atom.position.x, atom.position.y, atom.position.z);
            }
        }
        _ => println!("Unknown command"),
    }
}
