// LC 1857: Largest Color Value in DAG | LC 802: Find Eventual Safe States
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// LC 1857: Largest Color Value (Topological Sort + DP)
int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (auto& e : edges) { graph[e[0]].push_back(e[1]); indegree[e[1]]++; }
    
    vector<vector<int>> count(n, vector<int>(26, 0));
    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
    
    int processed = 0, result = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;
        count[u][colors[u] - 'a']++;
        result = max(result, count[u][colors[u] - 'a']);
        for (int v : graph[u]) {
            for (int c = 0; c < 26; c++) count[v][c] = max(count[v][c], count[u][c]);
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return processed == n ? result : -1;
}

// LC 802: Find Eventual Safe States (reverse graph)
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> rg(n);
    vector<int> outdegree(n);
    for (int u = 0; u < n; u++) {
        outdegree[u] = graph[u].size();
        for (int v : graph[u]) rg[v].push_back(u);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (outdegree[i] == 0) q.push(i);
    vector<bool> safe(n, false);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        safe[u] = true;
        for (int v : rg[u]) if (--outdegree[v] == 0) q.push(v);
    }
    vector<int> result;
    for (int i = 0; i < n; i++) if (safe[i]) result.push_back(i);
    return result;
}

int main() { cout << "DAG topological patterns\n"; return 0; }
