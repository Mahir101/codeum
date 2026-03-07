// LC 261: Graph Valid Tree | LC 323: Number of Connected Components
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent, rank_;
public:
    int components;
    UnionFind(int n) : parent(n), rank_(n, 0), components(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        components--;
        return true;
    }
};

// LC 261: Valid Tree (n nodes, n-1 edges, all connected, no cycle)
bool validTree(int n, vector<vector<int>>& edges) {
    if ((int)edges.size() != n - 1) return false;
    UnionFind uf(n);
    for (auto& e : edges)
        if (!uf.unite(e[0], e[1])) return false;
    return uf.components == 1;
}

// LC 323: Number of Connected Components
int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    for (auto& e : edges) uf.unite(e[0], e[1]);
    return uf.components;
}

int main() { cout << "Graph connectivity with Union Find\n"; return 0; }
