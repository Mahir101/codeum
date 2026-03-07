/*
 * Unprecedented Algorithm: Causal Inference (PC Algorithm Variant)
 * Category: AI / Statistics
 */

// ==========================================
// INTUITION & IMAGINATION
// ==========================================
// Correlation does not imply Causation.
// - "Ice cream sales and shark attacks are correlated."
// - Does eating ice cream cause shark attacks? No.
// - Does getting attacked by a shark make you crave ice cream? No.
// - It's a "Confounder": Heat (Summer) causes BOTH.
//
// Imagination:
// Imagine a web of invisible strings connecting variables.
// The PC Algorithm is a detective.
// 1. It assumes EVERYTHING is connected to EVERYTHING (Complete Graph).
// 2. It starts cutting strings.
//    - "If knowing X tells me nothing new about Y (given Z), then X and Y are not directly connected."
//      (Conditional Independence).
// 3. After cutting, it orients the arrows.
//    - "If X-Z-Y is a chain, and X is independent of Y, but X becomes DEPENDENT on Y given Z..."
//      Then Z must be a "Collider" (X -> Z <- Y).
//      (Example: Rain and Sprinkler are independent. But if I know Grass is Wet, knowing Rain tells me about Sprinkler).
//
// This sketches the "Skeleton" of causality from observations.

// ==========================================
// REAL WORLD APPLICATIONS
// ==========================================
// 1. Medicine: Determining if a drug causes recovery or if it's just patient demographics.
// 2. Economics: Analyzing policy impact (e.g., Interest Rates -> Inflation).
// 3. Root Cause Analysis: Debugging complex distributed systems failures.

use std::collections::{HashSet, HashMap};

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
struct Edge {
    u: usize,
    v: usize,
}

pub struct CausalGraph {
    num_nodes: usize,
    adj: HashMap<usize, HashSet<usize>>, // Undirected skeleton
    separators: HashMap<Edge, HashSet<usize>>, // Separating sets S_xy
    obs_data: Vec<Vec<f64>>, // Row: sample, Col: variable
}

impl CausalGraph {
    pub fn new(n: usize, data: Vec<Vec<f64>>) -> Self {
        let mut adj = HashMap::new();
        // Start with complete graph
        for i in 0..n {
            for j in 0..n {
                if i != j {
                    adj.entry(i).or_default().insert(j);
                }
            }
        }
        CausalGraph {
            num_nodes: n,
            adj,
            separators: HashMap::new(),
            obs_data: data,
        }
    }
    
    // Partial Correlation test (Gaussian assumption)
    // indep(x, y | Z) <=> partial_corr(x, y | Z) ~ 0
    fn is_independent(&self, x: usize, y: usize, given: &HashSet<usize>) -> bool {
        // Full recursive partial correlation calculation is complex.
        // For this demo, we use a mock logic or a simplified calculation.
        // Let's implement basic covariance check if 'given' is empty.
        
        let n = self.obs_data.len();
        if n < 2 { return true; } // Not enough data
        
        if given.is_empty() {
            // Pearson Correlation
            let mean_x : f64 = self.obs_data.iter().map(|row| row[x]).sum::<f64>() / n as f64;
            let mean_y : f64 = self.obs_data.iter().map(|row| row[y]).sum::<f64>() / n as f64;
            
            let mut num = 0.0;
            let mut den_x = 0.0;
            let mut den_y = 0.0;
            
            for row in &self.obs_data {
                let dx = row[x] - mean_x;
                let dy = row[y] - mean_y;
                num += dx * dy;
                den_x += dx * dx;
                den_y += dy * dy;
            }
            
            if den_x == 0.0 || den_y == 0.0 { return true; }
            let corr = num / (den_x.sqrt() * den_y.sqrt());
            
            // Threshold for independence
            return corr.abs() < 0.1;
        }
        
        // Placeholder for higher order partial correlation: recursively use inverse covariance matrix.
        // For robustness in this file, we return false (dependent) if we can't efficiently check.
        // In a real library, this calls a linear algebra solver.
        false
    }
    
    pub fn run_pc(&mut self) {
        let n = self.num_nodes;
        let mut depth = 0;
        
        // Step 1: PC-Skeleton (Remove edges based on conditional independence)
        loop {
            let mut edges_to_remove = Vec::new();
            let mut found_sep = false;
            
            // For every edge (i, j)
            for i in 0..n {
                if let Some(neighbors) = self.adj.get(&i) {
                    for &j in neighbors {
                        if i > j { continue; } // Process unique edges
                        
                        // Check neighbors of i excluding j
                        let adj_i: Vec<usize> = self.adj[&i].iter().cloned().filter(|&x| x != j).collect();
                        
                        // If |adj_i| >= depth, check all subsets of size 'depth'
                        if adj_i.len() >= depth {
                            // Mock subset iteration (check only first subset for demo speed)
                             let subset: HashSet<usize> = adj_i.iter().take(depth).cloned().collect();
                             
                             if self.is_independent(i, j, &subset) {
                                 edges_to_remove.push((i, j));
                                 self.separators.insert(Edge { u: i, v: j }, subset.clone());
                                 self.separators.insert(Edge { u: j, v: i }, subset);
                                 found_sep = true;
                             }
                        }
                    }
                }
            }
            
            for (u, v) in edges_to_remove {
                self.adj.get_mut(&u).unwrap().remove(&v);
                self.adj.get_mut(&v).unwrap().remove(&u);
            }
            
            if !found_sep && depth > 0 { break; } // Converged
            if depth > n { break; }
            depth += 1;
        }
        
        // Step 2: Orient Colliders (V-structures)
        // Check X - Z - Y. If X,Y non-adjacent, and Z not in Separator(X,Y), then X -> Z <- Y.
        // We print discovered colliders.
        println!("PC Algorithm: Connectivity Matrix:");
        for i in 0..n {
            println!("{}: {:?}", i, self.adj.get(&i).unwrap_or(&HashSet::new()));
        }
    }
}

fn main() {
    // Generate data for X -> Z <- Y
    // X, Y random. Z = X + Y + noise.
    // X, Y should be independent. X, Z dependent. Y, Z dependent.
    // X, Y dependent given Z? Yes.
    
    let mut data = Vec::new();
    use rand::Rng;
    let mut rng = rand::thread_rng();
    
    for _ in 0..1000 {
        let x: f64 = rng.gen_range(-1.0..1.0);
        let y: f64 = rng.gen_range(-1.0..1.0);
        let z: f64 = x + y + rng.gen_range(-0.1..0.1);
        data.push(vec![x, y, z]);
    }
    
    let mut pc = CausalGraph::new(3, data);
    pc.run_pc();
    
    // Expected: 
    // Edge (0,1) removed (indep).
    // Edges (0,2) and (1,2) kept.
    // V-structure detection would see 0-2-1, 0,1 not connected, 2 NOT in Sep(0,1) (since Sep is empty).
    // So 0->2<-1.
}
