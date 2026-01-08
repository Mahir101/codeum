// LC 1377: Frog Position After T Seconds | Tree DFS with Probability
#include <iostream>
#include <vector>
using namespace std;

// LC 1377: Frog Position After T Seconds
double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<int>> graph(n + 1);
    for (auto& e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    vector<bool> visited(n + 1, false);
    double result = 0;
    
    function<void(int, int, double)> dfs = [&](int node, int time, double prob) {
        if (time < 0) return;
        if (node == target) {
            int unvisitedChildren = 0;
            for (int child : graph[node]) if (!visited[child]) unvisitedChildren++;
            if (time == 0 || unvisitedChildren == 0) result = prob;
            return;
        }
        
        int unvisitedChildren = 0;
        for (int child : graph[node]) if (!visited[child]) unvisitedChildren++;
        if (unvisitedChildren == 0) return;
        
        visited[node] = true;
        for (int child : graph[node]) {
            if (!visited[child]) {
                dfs(child, time - 1, prob / unvisitedChildren);
            }
        }
    };
    
    visited[1] = true;
    dfs(1, t, 1.0);
    return result;
}

int main() {
    vector<vector<int>> edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    cout << "Frog at 2 after 2s: " << frogPosition(7, edges, 2, 4) << endl;
    return 0;
}
