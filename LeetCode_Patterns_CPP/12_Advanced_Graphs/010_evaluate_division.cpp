// LC 399: Evaluate Division (Weighted Union Find / BFS)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// BFS Approach
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                            vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> graph;
    for (int i = 0; i < (int)equations.size(); i++) {
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
    }
    
    auto bfs = [&](string& src, string& dst) -> double {
        if (!graph.count(src) || !graph.count(dst)) return -1.0;
        if (src == dst) return 1.0;
        unordered_map<string, double> visited;
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        visited[src] = 1.0;
        while (!q.empty()) {
            auto [node, val] = q.front(); q.pop();
            for (auto& [next, weight] : graph[node]) {
                if (!visited.count(next)) {
                    visited[next] = val * weight;
                    if (next == dst) return visited[next];
                    q.push({next, visited[next]});
                }
            }
        }
        return -1.0;
    };
    
    vector<double> result;
    for (auto& q : queries) result.push_back(bfs(q[0], q[1]));
    return result;
}

int main() {
    vector<vector<string>> eq = {{"a","b"},{"b","c"}};
    vector<double> vals = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"}};
    auto result = calcEquation(eq, vals, queries);
    cout << "a/c = " << result[0] << ", b/a = " << result[1] << endl;
    return 0;
}
