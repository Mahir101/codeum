// LC 787: Cheapest Flights Within K Stops | Bellman-Ford
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 787: Cheapest Flights Within K Stops
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    for (int i = 0; i <= k; i++) {
        vector<int> temp = dist;
        for (auto& f : flights) {
            if (dist[f[0]] != INT_MAX) {
                temp[f[1]] = min(temp[f[1]], dist[f[0]] + f[2]);
            }
        }
        dist = temp;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

// Bellman-Ford for negative weights
vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (auto& e : edges) {
            if (dist[e[0]] != INT_MAX && dist[e[0]] + e[2] < dist[e[1]]) {
                dist[e[1]] = dist[e[0]] + e[2];
            }
        }
    }
    
    // Check for negative cycles
    for (auto& e : edges) {
        if (dist[e[0]] != INT_MAX && dist[e[0]] + e[2] < dist[e[1]]) {
            return {};  // Negative cycle detected
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    cout << "Cheapest k=1: " << findCheapestPrice(3, flights, 0, 2, 1) << endl;
    return 0;
}
