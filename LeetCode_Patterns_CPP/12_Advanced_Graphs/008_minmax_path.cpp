// LC 778: Swim in Rising Water | LC 1631: Path With Min Effort
// Pattern: Binary Search + BFS/DFS or Modified Dijkstra
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 778: Swim in Rising Water (min max time)
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({grid[0][0], 0, 0});
    dist[0][0] = grid[0][0];
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    while (!pq.empty()) {
        auto [t, x, y] = pq.top(); pq.pop();
        if (x == n-1 && y == n-1) return t;
        if (t > dist[x][y]) continue;
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int newDist = max(t, grid[nx][ny]);
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    pq.push({newDist, nx, ny});
                }
            }
        }
    }
    return -1;
}

// LC 1631: Path With Minimum Effort (min max difference)
int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    while (!pq.empty()) {
        auto [effort, x, y] = pq.top(); pq.pop();
        if (x == m-1 && y == n-1) return effort;
        if (effort > dist[x][y]) continue;
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newDist = max(effort, abs(heights[nx][ny] - heights[x][y]));
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    pq.push({newDist, nx, ny});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> grid = {{0,2},{1,3}};
    cout << "Swim in water: " << swimInWater(grid) << endl;
    return 0;
}
