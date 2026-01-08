// LC 1584: Min Cost Connect Points using Prim's Algorithm
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 1584: Min Cost to Connect All Points (Prim's)
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> visited(n, false);
    // {cost, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    
    int totalCost = 0, edgesUsed = 0;
    
    while (edgesUsed < n) {
        auto [cost, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        totalCost += cost;
        edgesUsed++;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                pq.push({dist, v});
            }
        }
    }
    return totalCost;
}

// Prim's with Adjacency List
int primMST(int n, vector<vector<pair<int, int>>>& graph) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    int totalWeight = 0;
    
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += w;
        for (auto& [v, weight] : graph[u])
            if (!inMST[v]) pq.push({weight, v});
    }
    return totalWeight;
}

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Min cost: " << minCostConnectPoints(points) << endl;
    return 0;
}
