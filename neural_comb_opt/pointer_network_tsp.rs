// Neural Combinatorial Optimization: Pointer Networks for TSP
// Rust implementation of the C++ code with efficient tensor operations

use std::f64::consts::E;
use std::rc::Rc;
use std::cell::RefCell;
use rand::Rng;
use rand::seq::SliceRandom;

const HIDDEN_SIZE: usize = 128;
const INPUT_DIM: usize = 2;

#[derive(Clone, Debug, Copy)]
pub struct Point {
    x: f64,
    y: f64,
}

// Matrix operations helper (simplified for demonstration)
type Matrix = Vec<Vec<f64>>;
type Vector = Vec<f64>;

fn mat_mul_vec(m: &Matrix, v: &Vector) -> Vector {
    let rows = m.len();
    let cols = m[0].len();
    let mut res = vec![0.0; rows];
    for i in 0..rows {
        for j in 0..cols {
            res[i] += m[i][j] * v[j];
        }
    }
    res
}

fn sigmoid(x: f64) -> f64 { 1.0 / (1.0 + (-x).exp()) }
fn tanh(x: f64) -> f64 { x.tanh() }

struct LSTMCell {
    wf: Matrix, wi: Matrix, wc: Matrix, wo: Matrix,
    uf: Matrix, ui: Matrix, uc: Matrix, uo: Matrix,
    bf: Vector, bi: Vector, bc: Vector, bo: Vector,
    hidden_sz: usize,
    input_sz: usize,
}

impl LSTMCell {
    fn new(input_sz: usize, hidden_sz: usize) -> Self {
        let mut rng = rand::thread_rng();
        let init_mat = |r, c| (0..r).map(|_| (0..c).map(|_| rng.gen_range(-0.1..0.1)).collect()).collect();
        let init_vec = |n| vec![0.0; n];
        
        LSTMCell {
            wf: init_mat(hidden_sz, input_sz), wi: init_mat(hidden_sz, input_sz),
            wc: init_mat(hidden_sz, input_sz), wo: init_mat(hidden_sz, input_sz),
            uf: init_mat(hidden_sz, hidden_sz), ui: init_mat(hidden_sz, hidden_sz),
            uc: init_mat(hidden_sz, hidden_sz), uo: init_mat(hidden_sz, hidden_sz),
            bf: init_vec(hidden_sz), bi: init_vec(hidden_sz),
            bc: init_vec(hidden_sz), bo: init_vec(hidden_sz),
            hidden_sz, input_sz
        }
    }

    fn forward(&self, x: &Vector, h_prev: &Vector, c_prev: &Vector) -> (Vector, Vector) {
        let mut h_next = vec![0.0; self.hidden_sz];
        let mut c_next = vec![0.0; self.hidden_sz];
        
        for i in 0..self.hidden_sz {
            // Simplified loop for readability - in production usage we'd use BLAS
            let mut f: f64 = self.bf[i];
            let mut ig: f64 = self.bi[i];
            let mut ct: f64 = self.bc[i];
            let mut o: f64 = self.bo[i];
            
            for j in 0..self.input_sz {
                f += self.wf[i][j] * x[j];
                ig += self.wi[i][j] * x[j];
                ct += self.wc[i][j] * x[j];
                o += self.wo[i][j] * x[j];
            }
            
            for j in 0..self.hidden_sz {
                f += self.uf[i][j] * h_prev[j];
                ig += self.ui[i][j] * h_prev[j];
                ct += self.uc[i][j] * h_prev[j];
                o += self.uo[i][j] * h_prev[j];
            }
            
            f = sigmoid(f);
            ig = sigmoid(ig);
            ct = tanh(ct);
            o = sigmoid(o);
            
            c_next[i] = f * c_prev[i] + ig * ct;
            h_next[i] = o * tanh(c_next[i]);
        }
        
        (h_next, c_next)
    }
}

struct Attention {
    w1: Matrix,
    w2: Matrix,
    v: Vector,
}

impl Attention {
    fn new(hidden_sz: usize) -> Self {
        let mut rng = rand::thread_rng();
        let init_mat = |r, c| (0..r).map(|_| (0..c).map(|_| rng.gen_range(-0.1..0.1)).collect()).collect();
        let init_vec = |n| (0..n).map(|_| rng.gen_range(-0.1..0.1)).collect();
        
        Attention {
            w1: init_mat(hidden_sz, hidden_sz),
            w2: init_mat(hidden_sz, hidden_sz),
            v: init_vec(hidden_sz),
        }
    }
    
    fn compute_scores(&self, dec_state: &Vector, enc_states: &Vec<Vector>, mask: &Vec<bool>) -> Vector {
        let n = enc_states.len();
        let hidden_sz = self.v.len();
        let mut scores = vec![0.0; n];
        let mut max_score = f64::NEG_INFINITY;
        
        // Project decoder state once
        let mut dec_proj = vec![0.0; hidden_sz];
        for i in 0..hidden_sz {
            for j in 0..hidden_sz {
                dec_proj[i] += self.w2[i][j] * dec_state[j];
            }
        }
        
        for i in 0..n {
            if mask[i] { 
                scores[i] = f64::NEG_INFINITY; 
                continue; 
            }
            
            let mut score_val = 0.0;
            // Calculate tanh(W1*enc + W2*dec) . v
            for k in 0..hidden_sz {
                let mut sum = dec_proj[k];
                for j in 0..hidden_sz {
                    sum += self.w1[k][j] * enc_states[i][j];
                }
                score_val += tanh(sum) * self.v[k];
            }
            
            scores[i] = score_val;
            if score_val > max_score { max_score = score_val; }
        }
        
        // Softmax
        let mut sum_exp = 0.0;
        for i in 0..n {
            if !mask[i] {
                scores[i] = (scores[i] - max_score).exp();
                sum_exp += scores[i];
            } else {
                scores[i] = 0.0;
            }
        }
        
        for i in 0..n { scores[i] /= sum_exp; }
        scores
    }
}

struct PointerNetwork {
    encoder: LSTMCell,
    decoder: LSTMCell,
    attention: Attention,
}

impl PointerNetwork {
    fn new() -> Self {
        PointerNetwork {
            encoder: LSTMCell::new(INPUT_DIM, HIDDEN_SIZE),
            decoder: LSTMCell::new(INPUT_DIM, HIDDEN_SIZE),
            attention: Attention::new(HIDDEN_SIZE),
        }
    }
    
    fn solve_tsp(&self, cities: &Vec<Point>) -> Vec<usize> {
        let n = cities.len();
        
        // 1. Encoding
        let mut enc_states = Vec::new();
        let mut h_curr = vec![0.0; HIDDEN_SIZE];
        let mut c_curr = vec![0.0; HIDDEN_SIZE];
        
        for point in cities {
            let x = vec![point.x, point.y];
            let (h_next, c_next) = self.encoder.forward(&x, &h_curr, &c_curr);
            h_curr = h_next;
            c_curr = c_next;
            enc_states.push(h_curr.clone());
        }
        
        // 2. Decoding
        let mut tour = Vec::new();
        let mut visited = vec![false; n];
        let mut dec_input = vec![0.0; 2]; // Start token
        let mut dec_h = h_curr; // Init with last encoder state
        let mut dec_c = c_curr;
        
        for _ in 0..n {
            let (h_next, c_next) = self.decoder.forward(&dec_input, &dec_h, &dec_c);
            dec_h = h_next;
            dec_c = c_next;
            
            let probs = self.attention.compute_scores(&dec_h, &enc_states, &visited);
            
            // Greedy selection
            let mut next_city = 0;
            let mut max_prob = -1.0;
            
            for i in 0..n {
                if !visited[i] && probs[i] > max_prob {
                    max_prob = probs[i];
                    next_city = i;
                }
            }
            
            visited[next_city] = true;
            tour.push(next_city);
            
            dec_input = vec![cities[next_city].x, cities[next_city].y];
        }
        
        tour
    }
}

fn main() {
    println!("Neural Combinatorial Optimization: TSP Solver");
    let mut rng = rand::thread_rng();
    let n = 10;
    let cities: Vec<Point> = (0..n).map(|_| Point {
        x: rng.gen(),
        y: rng.gen(),
    }).collect();
    
    for (i, p) in cities.iter().enumerate() {
        println!("City {}: ({:.2}, {:.2})", i, p.x, p.y);
    }
    
    let model = PointerNetwork::new();
    let tour = model.solve_tsp(&cities);
    
    println!("\nPredicted Tour: {:?}", tour);
    
    // Calculate distance
    let mut dist = 0.0;
    for i in 0..n-1 {
        let p1 = cities[tour[i]];
        let p2 = cities[tour[i+1]];
        dist += ((p1.x - p2.x).powi(2) + (p1.y - p2.y).powi(2)).sqrt();
    }
    let start = cities[tour[0]];
    let end = cities[tour[n-1]];
    dist += ((start.x - end.x).powi(2) + (start.y - end.y).powi(2)).sqrt();
    
    println!("Total Distance: {:.4}", dist);
}
