// LC 1584: Min Cost to Connect All Points | Pattern: Prim's/Kruskal's MST
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Prim's Algorithm
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0});
    int cost = 0, edges = 0;
    
    while (edges < n) {
        auto [dist, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        cost += dist;
        edges++;
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int d = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                pq.push({d, v});
            }
        }
    }
    return cost;
}

int main() {
    vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    cout << "Min cost: " << minCostConnectPoints(points) << endl;
    return 0;
}
