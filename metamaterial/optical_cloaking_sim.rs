/*
 * Unprecedented Algorithm: Metamaterial Optical Cloaking Simulation
 * Category: Physics / Computational Geometry
 */

// ==========================================
// INTUITION & IMAGINATION
// ==========================================
// Invisibility Cloaks are not magic; they are geometry.
// Light travels in straight lines (geodesics) in vacuum.
// In a medium with varying Refractive Index n(x), light bends (Snell's Law).
//
// Imagination:
// Imagine a river flowing around a rock. The water splits, goes around, and rejoins perfectly.
// If you look downstream, you don't see the "disturbance" of the rock.
// We want to do this with Light.
//
// We design a material where the refractive index varies spatially such that light rays
// are smoothly guided *around* a central region (the cloaked object) and exit as if they
// passed straight through.
//
// This requires Transformation Optics:
// We start with a flat space metric (straight lines).
// We apply a coordinate transformation (stretching a point into a hole).
// The math tells us exactly what Permittivity (epsilon) and Permeability (mu) tensors are needed.

// ==========================================
// REAL WORLD APPLICATIONS
// ==========================================
// 1. Stealth Technology: Hiding objects from Radar (Microwaves).
// 2. Acoustics: Sound-proof rooms that guide sound waves around them.
// 3. Seismic Protection: Guiding earthquake waves around buildings.

struct Ray {
    pos: (f64, f64),
    dir: (f64, f64),
}

// Coordinate Transformation Logic
// r' = R1 + r * (R2 - R1) / R2  (Compressing space 0..R2 into annulus R1..R2)
fn transform_metric(x: f64, y: f64) -> (f64, f64) {
    let r = (x*x + y*y).sqrt();
    let r1 = 1.0; // Inner radius (Cloak region)
    let r2 = 3.0; // Outer radius
    
    if r < r1 {
        // Inside the hole - theoretically unreachable by rays
        (0.0, 0.0)
    } else if r < r2 {
        // Inside cloak
        // Just return gradients or new direction modifiers
        // For simplicity in ray marching, we use the effective refractive index gradient.
        // Gradient points outward slightly to curve rays around.
        let factor = (r - r1) / (r2 - r1);
        (x * factor, y * factor)
    } else {
        (x, y)
    }
}

// Runge-Kutta Ray Tracing for Gradient Index Optics
pub fn trace_ray_through_cloak(mut ray: Ray) -> Vec<(f64, f64)> {
    let mut unique_path = Vec::new();
    let dt = 0.05;
    
    let r1 = 1.0;
    let r2 = 3.0;
    
    for _ in 0..200 {
        unique_path.push(ray.pos);
        
        // Eikonal Equation Approximation
        // dn/dr for a Pendry Cloak is effectively creating a "repulsive" force from r=0
        let r_sq = ray.pos.0.powi(2) + ray.pos.1.powi(2);
        let r = r_sq.sqrt();
        
        if r < r2 && r > r1 {
            // "Force" to bend ray around
            // Tangential component preserved, Radial component reduced?
            // Simple visual simulation:
            // Add a force perpendicular to velocity, away from center
            
            // Vector to center
            let to_center_x = -ray.pos.0;
            let to_center_y = -ray.pos.1;
            
            // Cross product (2D) to find "Right" vector relative to radius
            // We want to bend velocity such that it becomes tangential.
            
            // Heuristic bending force
            let bend_strength = 0.1 / (r - r1 + 0.1); // Stronger near core
            
            // Deflect velocity away from center normal?
            // Actually, we deflect it so it doesn't enter r < r1.
            let dot = ray.dir.0 * to_center_x + ray.dir.1 * to_center_y;
            if dot > 0.0 { // Moving inwards
                 // Push orthogonal to velocity
                 ray.dir.0 += ray.pos.0 * bend_strength * dt;
                 ray.dir.1 += ray.pos.1 * bend_strength * dt;
            }
            
            // Normalize speed (assuming n=1 effective speed roughly, though n varies)
            let speed = (ray.dir.0.powi(2) + ray.dir.1.powi(2)).sqrt();
            ray.dir.0 /= speed;
            ray.dir.1 /= speed;
        }
        
        ray.pos.0 += ray.dir.0 * dt;
        ray.pos.1 += ray.dir.1 * dt;
    }
    unique_path
}

fn main() {
    // Fire ray at the cloak
    let ray = Ray { pos: (-5.0, 1.5), dir: (1.0, 0.0) };
    let path = trace_ray_through_cloak(ray);
    println!("Ray Steps: {}", path.len());
    println!("Final Pos: ({:.2}, {:.2})", path.last().unwrap().0, path.last().unwrap().1);
    // Should pass through to roughly (5.0, 1.5) if cloaking worked perfectly,
    // or at least miss the center (0,0).
}
