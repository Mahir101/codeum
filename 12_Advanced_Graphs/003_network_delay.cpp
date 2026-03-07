// LC 743: Network Delay Time | Pattern: Dijkstra's Algorithm
// Time: O((V+E)logV) | Space: O(V+E)
// Recognition: "Shortest path from source in weighted graph"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> graph(n + 1);
    for (auto& t : times) graph[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    int maxDist = 0;
    for (int i = 1; i <= n; i++) maxDist = max(maxDist, dist[i]);
    return maxDist == INT_MAX ? -1 : maxDist;
}

int main() {
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    cout << "Network delay: " << networkDelayTime(times, 4, 2) << endl;
    return 0;
}
