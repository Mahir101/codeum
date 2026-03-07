// LC 834: Sum of Distances in Tree | LC 310: Minimum Height Trees (Re-rooting)
#include <iostream>
#include <vector>
using namespace std;

// LC 834: Sum of Distances in Tree (Re-rooting DP)
class Solution {
    vector<vector<int>> graph;
    vector<int> count, ans;
    int n;
    
    void dfs1(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs1(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                // ans[child] = ans[node] - count[child] + (n - count[child])
                ans[child] = ans[node] - 2 * count[child] + n;
                dfs2(child, node);
            }
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.resize(n);
        count.resize(n, 1);
        ans.resize(n, 0);
        
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs1(0, -1);
        dfs2(0, -1);
        
        return ans;
    }
};

int main() {
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    Solution sol;
    auto result = sol.sumOfDistancesInTree(6, edges);
    cout << "Sum of distances: ";
    for (int d : result) cout << d << " ";
    cout << endl;
    return 0;
}
