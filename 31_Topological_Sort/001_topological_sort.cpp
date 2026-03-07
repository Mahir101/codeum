// Topological Sort Pattern
// LC 207: Course Schedule | LC 210: Course Schedule II | LC 269: Alien Dictionary
// LC 310: Minimum Height Trees | LC 1136: Parallel Courses
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Kahn's Algorithm (BFS)
vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (auto& e : edges) { graph[e[0]].push_back(e[1]); indegree[e[1]]++; }
    
    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
    
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : graph[u]) if (--indegree[v] == 0) q.push(v);
    }
    return order.size() == n ? order : vector<int>{};  // Empty if cycle
}

// LC 207: Can Finish All Courses
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    return topologicalSort(numCourses, prerequisites).size() == numCourses;
}

// LC 210: Course Order
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);
    vector<vector<int>> edges;
    for (int i = 0; i < numCourses; i++)
        for (int j : adj[i]) edges.push_back({i, j});
    return topologicalSort(numCourses, edges);
}

// LC 310: Minimum Height Trees (topological peeling)
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<int> degree(n, 0);
    vector<vector<int>> graph(n);
    for (auto& e : edges) {
        graph[e[0]].push_back(e[1]); graph[e[1]].push_back(e[0]);
        degree[e[0]]++; degree[e[1]]++;
    }
    queue<int> leaves;
    for (int i = 0; i < n; i++) if (degree[i] == 1) leaves.push(i);
    while (n > 2) {
        int size = leaves.size(); n -= size;
        while (size--) {
            int leaf = leaves.front(); leaves.pop();
            for (int neighbor : graph[leaf])
                if (--degree[neighbor] == 1) leaves.push(neighbor);
        }
    }
    vector<int> result;
    while (!leaves.empty()) { result.push_back(leaves.front()); leaves.pop(); }
    return result;
}

int main() { cout << "Topological Sort Pattern\n"; return 0; }
