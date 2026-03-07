// LC 1483: Kth Ancestor of a Tree Node | Binary Lifting
#include <iostream>
#include <vector>
using namespace std;

// LC 1483: Kth Ancestor (Binary Lifting)
class TreeAncestor {
    vector<vector<int>> up;  // up[i][j] = 2^j-th ancestor of i
    int LOG;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        up.assign(n, vector<int>(LOG, -1));
        
        for (int i = 0; i < n; i++) up[i][0] = parent[i];
        
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j-1] != -1)
                    up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG && node != -1; j++) {
            if ((k >> j) & 1) node = up[node][j];
        }
        return node;
    }
};

// LCA with Binary Lifting
class LCA {
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
    
public:
    LCA(int n, vector<vector<int>>& adj, int root = 0) {
        LOG = 0; while ((1 << LOG) <= n) LOG++;
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);
        dfs(root, -1, adj);
    }
    
    void dfs(int v, int p, vector<vector<int>>& adj) {
        up[v][0] = p;
        for (int j = 1; j < LOG; j++)
            if (up[v][j-1] != -1) up[v][j] = up[up[v][j-1]][j-1];
        for (int u : adj[v]) if (u != p) { depth[u] = depth[v] + 1; dfs(u, v, adj); }
    }
    
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) if ((diff >> j) & 1) a = up[a][j];
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; j--)
            if (up[a][j] != up[b][j]) { a = up[a][j]; b = up[b][j]; }
        return up[a][0];
    }
};

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    TreeAncestor ta(7, parent);
    cout << "3rd ancestor of 6: " << ta.getKthAncestor(6, 3) << endl;
    return 0;
}
