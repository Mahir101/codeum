/**
 * Neural Combinatorial Optimization: Pointer Networks for TSP
 * 
 * Implements a Pointer Network architecture inference engine for solving 
 * Traveling Salesman Problem (TSP).
 * 
 * Architecture:
 * - Encoder: Bidirectional LSTM
 * - Decoder: Uni-directional LSTM with Attention mechanism (Pointer)
 * 
 * References: Vinyals et al. "Pointer Networks" (NeurIPS 2015)
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

// Hyperparameters
const int HIDDEN_SIZE = 128;
const int INPUT_DIM = 2; // (x, y) coordinates

struct Point {
    double x, y;
};

// Simplified LSTM Cell for inference
class LSTMCell {
    // Weights would normally be loaded from a trained model
    // Here we use random initialization for demonstration of the architecture structure
    vector<vector<double>> Wf, Wi, Wc, Wo; // Input weights
    vector<vector<double>> Uf, Ui, Uc, Uo; // Recurrent weights
    vector<double> bf, bi, bc, bo;         // Biases
    int input_sz, hidden_sz;

public:
    LSTMCell(int input_size, int hidden_size) : input_sz(input_size), hidden_sz(hidden_size) {
        // Initialize weights (dummy initialization)
        initialize_weights(Wf, input_sz, hidden_sz);
        initialize_weights(Wi, input_sz, hidden_sz);
        initialize_weights(Wc, input_sz, hidden_sz);
        initialize_weights(Wo, input_sz, hidden_sz);
        initialize_weights(Uf, hidden_sz, hidden_sz);
        initialize_weights(Ui, hidden_sz, hidden_sz);
        initialize_weights(Uc, hidden_sz, hidden_sz);
        initialize_weights(Uo, hidden_sz, hidden_sz);
        
        bf.resize(hidden_sz, 0.0);
        bi.resize(hidden_sz, 0.0);
        bc.resize(hidden_sz, 0.0);
        bo.resize(hidden_sz, 0.0);
    }

    void initialize_weights(vector<vector<double>>& W, int r, int c) {
        W.resize(r, vector<double>(c));
        mt19937 gen(42);
        normal_distribution<> d(0, 0.1);
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                W[i][j] = d(gen);
    }

    void forward(const vector<double>& x, const vector<double>& h_prev, const vector<double>& c_prev,
                 vector<double>& h_next, vector<double>& c_next) {
        
        h_next.assign(hidden_sz, 0.0);
        c_next.assign(hidden_sz, 0.0);
        
        // Simplification: Standard LSTM gates
        for(int i=0; i<hidden_sz; i++) {
            double f = 0, i_g = 0, c_tmp = 0, o = 0;
            
            for(int j=0; j<input_sz; j++) {
                f += x[j] * Wf[j][i];
                i_g += x[j] * Wi[j][i];
                c_tmp += x[j] * Wc[j][i];
                o += x[j] * Wo[j][i];
            }
            for(int j=0; j<hidden_sz; j++) {
                f += h_prev[j] * Uf[j][i];
                i_g += h_prev[j] * Ui[j][i];
                c_tmp += h_prev[j] * Uc[j][i];
                o += h_prev[j] * Uo[j][i];
            }
            
            f = sigmoid(f + bf[i]);
            i_g = sigmoid(i_g + bi[i]);
            c_tmp = tanh(c_tmp + bc[i]);
            o = sigmoid(o + bo[i]);
            
            c_next[i] = f * c_prev[i] + i_g * c_tmp;
            h_next[i] = o * tanh(c_next[i]);
        }
    }

    double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
};

class Attention {
    vector<vector<double>> W1, W2;
    vector<double> v;
    int hidden_sz;

public:
    Attention(int hidden_sz) : hidden_sz(hidden_sz) {
        // W1: encoder states -> hidden
        // W2: decoder state -> hidden
        // v:  hidden -> score
        // Init with random weights
        W1.resize(hidden_sz, vector<double>(hidden_sz, 0.01));
        W2.resize(hidden_sz, vector<double>(hidden_sz, 0.01));
        v.resize(hidden_sz, 0.01);
    }
    
    // Luong Attention variant / Pointer Mechanism
    vector<double> compute_scores(const vector<double>& decoder_state, const vector<vector<double>>& encoder_states, const vector<bool>& mask) {
        vector<double> scores(encoder_states.size());
        double max_score = -1e9;
        
        for(size_t i=0; i<encoder_states.size(); i++) {
            if(mask[i]) {
                scores[i] = -1e9;
                continue;
            }
            
            // Score = v^T * tanh(W1 * enc_i + W2 * dec)
            double score = 0;
            for(int k=0; k<hidden_sz; k++) {
                double val = 0;
                for(int j=0; j<hidden_sz; j++) {
                    val += encoder_states[i][j] * W1[j][k];
                    val += decoder_state[j] * W2[j][k];
                }
                score += tanh(val) * v[k];
            }
            scores[i] = score;
            if (score > max_score) max_score = score;
        }
        
        // Softmax
        double sum_exp = 0;
        for(size_t i=0; i<scores.size(); i++) {
            if(!mask[i]) {
                scores[i] = exp(scores[i] - max_score);
                sum_exp += scores[i];
            } else {
                scores[i] = 0;
            }
        }
        for(size_t i=0; i<scores.size(); i++) scores[i] /= sum_exp;
        
        return scores; // Probabilities pointing to input elements
    }
};

class PointerNetwork {
    LSTMCell encoder;
    LSTMCell decoder;
    Attention attention;
    int hidden_size;

public:
    PointerNetwork(int hidden_size) 
        : encoder(INPUT_DIM, hidden_size), 
          decoder(INPUT_DIM, hidden_size), 
          attention(hidden_size),
          hidden_size(hidden_size) {}

    vector<int> solve_tsp(const vector<Point>& input_seq) {
        int seq_len = input_seq.size();
        
        // 1. Encoder Step
        vector<vector<double>> encoder_states(seq_len, vector<double>(hidden_size));
        vector<double> h_curr(hidden_size, 0.0), c_curr(hidden_size, 0.0);
        
        for(int i=0; i<seq_len; i++) {
            vector<double> x = {input_seq[i].x, input_seq[i].y};
            vector<double> h_next, c_next;
            encoder.forward(x, h_curr, c_curr, h_next, c_next);
            h_curr = h_next;
            c_curr = c_next;
            encoder_states[i] = h_curr;
        }
        
        // Decoder Step (Pointer Mechanism)
        vector<int> tour;
        vector<bool> visited(seq_len, false);
        
        // Initial decoder input (start token, typically 0,0 or learned)
        vector<double> dec_input = {0.0, 0.0}; 
        vector<double> dec_h = h_curr; // Init with last encoder state
        vector<double> dec_c = c_curr;
        
        for(int step=0; step<seq_len; step++) {
            vector<double> h_next, c_next;
            decoder.forward(dec_input, dec_h, dec_c, h_next, c_next);
            dec_h = h_next;
            dec_c = c_next;
            
            // Attention over encoder states determines the pointer
            vector<double> probs = attention.compute_scores(dec_h, encoder_states, visited);
            
            // Argmax selection (Greedy decoding)
            int next_city = -1;
            double max_prob = -1.0;
            for(int i=0; i<seq_len; i++) {
                if(!visited[i] && probs[i] > max_prob) {
                    max_prob = probs[i];
                    next_city = i;
                }
            }
            
            if (next_city == -1) break; // Should not happen
            
            visited[next_city] = true;
            tour.push_back(next_city);
            
            // Next input is the coordinates of the selected city
            dec_input = {input_seq[next_city].x, input_seq[next_city].y};
        }
        
        return tour;
    }
};

int main() {
    cout << "Neural Combinatorial Optimization: Pointer Network for TSP" << endl;
    cout << "==========================================================" << endl;
    
    // Generate random TSP instance
    int N = 10;
    vector<Point> cities(N);
    mt19937 gen(42);
    uniform_real_distribution<> dis(0.0, 1.0);
    
    cout << "Cities:" << endl;
    for(int i=0; i<N; i++) {
        cities[i] = {dis(gen), dis(gen)};
        cout << i << ": (" << fixed << setprecision(3) << cities[i].x << ", " << cities[i].y << ")" << endl;
    }
    
    // Instantiate Model
    PointerNetwork model(HIDDEN_SIZE);
    
    // Solve
    vector<int> tour = model.solve_tsp(cities);
    
    cout << "\nPredicted Tour sequence:" << endl;
    for(size_t i=0; i<tour.size(); i++) {
        cout << tour[i] << (i < tour.size()-1 ? " -> " : "");
    }
    cout << endl;
    
    // Calculate distance
    double dist = 0;
    for(size_t i=0; i<tour.size()-1; i++) {
        double dx = cities[tour[i]].x - cities[tour[i+1]].x;
        double dy = cities[tour[i]].y - cities[tour[i+1]].y;
        dist += sqrt(dx*dx + dy*dy);
    }
    // Return to start
    double dx = cities[tour.back()].x - cities[tour[0]].x;
    double dy = cities[tour.back()].y - cities[tour[0]].y;
    dist += sqrt(dx*dx + dy*dy);
    
    cout << "Total Tour Distance: " << dist << endl;
    
    return 0;
}
