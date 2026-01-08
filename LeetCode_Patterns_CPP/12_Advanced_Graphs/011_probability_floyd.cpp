// LC 1514: Path with Maximum Probability | LC 1334: Find City with Smallest Neighbors
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 1514: Maximum Probability Path (modified Dijkstra)
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < (int)edges.size(); i++) {
        graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
        graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    
    vector<double> prob(n, 0);
    prob[start] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});
    
    while (!pq.empty()) {
        auto [p, u] = pq.top(); pq.pop();
        if (u == end) return p;
        if (p < prob[u]) continue;
        for (auto& [v, edgeProb] : graph[u]) {
            if (prob[u] * edgeProb > prob[v]) {
                prob[v] = prob[u] * edgeProb;
                pq.push({prob[v], v});
            }
        }
    }
    return 0;
}

// LC 1334: Find the City With the Smallest Number of Neighbors (Floyd-Warshall)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (auto& e : edges) { dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2]; }
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    int result = 0, minCount = n;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) if (dist[i][j] <= distanceThreshold) count++;
        if (count <= minCount) { minCount = count; result = i; }
    }
    return result;
}

int main() { cout << "Max Probability and Find City\n"; return 0; }
