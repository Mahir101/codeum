/*
 * Unprecedented Algorithm: Neuroevolution of Augmenting Topologies (NEAT Variant)
 * Category: AI / Evolutionary Algorithms
 */

// ==========================================
// INTUITION & IMAGINATION
// ==========================================
// Neural Networks calculate gradients to find weights.
// But who designed the *architecture* (layers, connections)? Humans.
// Can Evolution design the brain structure too?
//
// Imagination:
// Imagine a primoridal soup of simple brains (just input connected to output).
// We let them control a creature. The ones that survive pass on their genes.
//
// Mutation 1: Change a weight (like Gradient Descent, but random).
// Mutation 2: Add a Connection (New synapse).
// Mutation 3: Add a Node (Split a connection into two). This grows the brain's complexity!
//
// Critical Innovation (Speciation):
// If a brain mutates a new structure, it will initially be clumsy (untrained weights).
// Standard evolution would kill it immediately.
// We protect new species in separate "niches" so they have time to optimize their new structure.
// This allows the algorithm to start simple and *complexify* only when needed.

// ==========================================
// REAL WORLD APPLICATIONS
// ==========================================
// 1. Robotics: Evolving walking gaits for damaged robots (adaptation).
// 2. Game AI: Creating agents for games with unknown rules.
// 3. Architecture Search: Finding efficient ConvNet structures (AutoML).

use std::collections::HashMap;
use rand::Rng;

#[derive(Clone, Debug, PartialEq)]
struct Gene {
    in_node: usize,
    out_node: usize,
    weight: f64,
    enabled: bool,
    innovation_num: usize,
}

#[derive(Clone, Debug)]
struct Genome {
    genes: Vec<Gene>,
    fitness: f64,
    species_id: usize,
}

impl Genome {
    fn new_minimal() -> Self {
        Genome { genes: Vec::new(), fitness: 0.0, species_id: 0 }
    }
    
    // Mutation: Alter Weights
    fn mutate_weights(&mut self) {
        let mut rng = rand::thread_rng();
        for gene in &mut self.genes {
            if rng.gen_bool(0.1) {
                gene.weight += rng.gen_range(-0.5..0.5);
            } else if rng.gen_bool(0.01) {
                gene.weight = rng.gen_range(-2.0..2.0); // Reset
            }
        }
    }
    
    // Mutation: Add Connection
    fn mutate_add_link(&mut self, max_nodes: usize, innovation_counter: &mut usize) {
        let mut rng = rand::thread_rng();
        let i = rng.gen_range(0..max_nodes);
        let j = rng.gen_range(0..max_nodes);
        
        // Check if exists
        for g in &self.genes {
            if g.in_node == i && g.out_node == j { return; }
        }
        
        *innovation_counter += 1;
        self.genes.push(Gene {
            in_node: i,
            out_node: j,
            weight: rng.gen_range(-1.0..1.0),
            enabled: true,
            innovation_num: *innovation_counter,
        });
    }
    
    // Crossover: align homologous genes
    fn crossover(p1: &Genome, p2: &Genome) -> Genome {
        let mut child_genes = Vec::new();
        let mut i = 0;
        let mut j = 0;
        
        // Assuming genes are sorted by innovation_num
        while i < p1.genes.len() && j < p2.genes.len() {
            let g1 = &p1.genes[i];
            let g2 = &p2.genes[j];
            
            if g1.innovation_num == g2.innovation_num {
                // Match: Pick random parent's weight
                if rand::thread_rng().gen_bool(0.5) {
                    child_genes.push(g1.clone());
                } else {
                    child_genes.push(g2.clone());
                }
                i += 1;
                j += 1;
            } else if g1.innovation_num < g2.innovation_num {
                // Disjoint: Take from fit parent (assume p1 is fitter)
                child_genes.push(g1.clone());
                i += 1;
            } else {
                // Disjoint: Skip (p2 is less fit)
                j += 1;
            }
        }
        
        // Excess genes from p1
        while i < p1.genes.len() {
            child_genes.push(p1.genes[i].clone());
            i += 1;
        }
        
        Genome { genes: child_genes, fitness: 0.0, species_id: 0 }
    }
}

pub fn evolve_population() {
    println!("Neuroevolution Engine Started...");
    let mut pop = vec![Genome::new_minimal(); 10];
    let mut innovation = 0;
    
    for gen in 0..5 {
        println!("Generation {}", gen);
        // Evaluate
        for g in &mut pop {
            g.fitness = rand::thread_rng().gen_range(0.0..100.0); // Mock Eval
        }
        
        // Sort by fitness
        pop.sort_by(|a, b| b.fitness.partial_cmp(&a.fitness).unwrap());
        
        // Reproduce (Top 5)
        let mut new_pop = Vec::new();
        for i in 0..5 {
            let mut child = pop[i].clone();
            child.mutate_weights();
            child.mutate_add_link(5, &mut innovation);
            new_pop.push(child);
            
            // Crossover with next best
            if i < 4 {
                let child2 = Genome::crossover(&pop[i], &pop[i+1]);
                new_pop.push(child2);
            }
        }
        pop = new_pop;
    }
    println!("Best Genome Fitness: {:.2}", pop[0].fitness);
    println!("Genome Complexity: {} connections", pop[0].genes.len());
}

fn main() {
    evolve_population();
}
