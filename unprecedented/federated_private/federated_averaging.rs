/*
 * Unprecedented Algorithm: Federated Learning (FedAvg)
 * Category: AI / Privacy
 */

// ==========================================
// INTUITION & IMAGINATION
// ==========================================
// Problem: Train a massive AI model on hospital patient data.
// Hospital A cannot share data with Hospital B (Privacy Laws).
// Central Server cannot see the data either.
//
// Imagination:
// Imagine a team of chefs (Clients) trying to perfect a cake recipe (Global Model).
// They cannot visit each other's kitchens (Privacy).
// 1. Master Chef sends the current recipe to all local chefs.
// 2. Local chefs bake a cake, taste it, and tweak the recipe slightly based on their local ingredients.
// 3. They send ONLY the "Tweaks" (Gradients/Weights) back to the Master Chef. Not the ingredients.
// 4. Master Chef averages all the tweaks and updates the global recipe.
// 5. Repeat.
//
// The Global Model gets smarter, but the raw data never left the local devices.
//
// Challenge: Non-IID data (Hospital A has only flu, Hospital B has only fractures).
// FedAvg handles this robustly by averaging weights rather than gradients.

// ==========================================
// REAL WORLD APPLICATIONS
// ==========================================
// 1. Mobile Keyboards: Gboard learns new words from millions of users without reading your texts.
// 2. Healthcare: Collaborative cancer detection models across varying hospitals.
// 3. Finance: Fraud detection across banks without sharing transaction logs.

struct Model {
    weights: Vec<f64>,
}

impl Model {
    fn average(models: &[Model]) -> Model {
        let n = models.len();
        let size = models[0].weights.len();
        let mut new_weights = vec![0.0; size];
        
        for m in models {
            for i in 0..size {
                new_weights[i] += m.weights[i];
            }
        }
        
        for i in 0..size {
            new_weights[i] /= n as f64;
        }
        
        Model { weights: new_weights }
    }
}

pub fn simulate_fed_avg() {
    let global_model = Model { weights: vec![0.5, 0.5] };
    
    // Round 1: Clients train locally
    let client1_update = Model { weights: vec![0.6, 0.4] }; // Learned from local data
    let client2_update = Model { weights: vec![0.4, 0.6] };
    
    // Aggregation
    let new_global = Model::average(&[client1_update, client2_update]);
    
    println!("New Global Weights: {:?}", new_global.weights); // [0.5, 0.5]
}

fn main() {
    simulate_fed_avg();
}
