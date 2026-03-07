// LC 1584: Min Cost to Connect All Points | LC 1168: Optimize Water Distribution
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class UnionFind {
    vector<int> parent, rank_;
public:
    UnionFind(int n) : parent(n), rank_(n, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { if (parent[x] != x) parent[x] = find(parent[x]); return parent[x]; }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
};

// LC 1584: Min Cost to Connect All Points (Kruskal's MST)
int minCostConnectPointsKruskal(vector<vector<int>>& points) {
    int n = points.size();
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges.push_back({dist, i, j});
        }
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n);
    int cost = 0, edgesUsed = 0;
    for (auto& [d, u, v] : edges) {
        if (uf.unite(u, v)) {
            cost += d;
            if (++edgesUsed == n - 1) break;
        }
    }
    return cost;
}

// LC 1168: Optimize Water (add virtual node for wells)
int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) edges.push_back({wells[i], 0, i + 1});
    for (auto& p : pipes) edges.push_back({p[2], p[0], p[1]});
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n + 1);
    int cost = 0;
    for (auto& [w, u, v] : edges)
        if (uf.unite(u, v)) cost += w;
    return cost;
}

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Min cost: " << minCostConnectPointsKruskal(points) << endl;
    return 0;
}
