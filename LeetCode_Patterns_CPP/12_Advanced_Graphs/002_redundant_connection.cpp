// LC 684: Redundant Connection | Pattern: Union Find
// Time: O(n * α(n)) ≈ O(n) | Space: O(n)
// Recognition: "Find edge causing cycle in graph"
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent, rank_;
public:
    UnionFind(int n) : parent(n + 1), rank_(n + 1, 0) {
        for (int i = 0; i <= n; i++) parent[i] = i;
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
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size());
    for (auto& e : edges) {
        if (!uf.unite(e[0], e[1])) return e;
    }
    return {};
}

int main() {
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};
    auto res = findRedundantConnection(edges);
    cout << "Redundant: [" << res[0] << "," << res[1] << "]\n";
    return 0;
}
