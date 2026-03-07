// LC 1192: Critical Connections | Articulation Points (Tarjan's Algorithm)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int timer = 0;
    vector<vector<int>> bridges;
    vector<int> disc, low;
    
    void dfs(vector<vector<int>>& graph, int u, int parent) {
        disc[u] = low[u] = timer++;
        for (int v : graph[u]) {
            if (disc[v] == -1) {
                dfs(graph, v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) bridges.push_back({u, v});
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        disc.assign(n, -1); low.assign(n, -1);
        for (int i = 0; i < n; i++)
            if (disc[i] == -1) dfs(graph, i, -1);
        return bridges;
    }
};

int main() {
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    Solution sol;
    auto bridges = sol.criticalConnections(4, connections);
    cout << "Bridges: " << bridges.size() << endl;
    return 0;
}
