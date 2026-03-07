// LC 1293: Shortest Path in Grid with Obstacles | LC 1197: Minimum Knight Moves
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 1293: Shortest Path with K Obstacles Elimination
int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if (k >= m + n - 3) return m + n - 2;
    
    vector<vector<int>> seen(m, vector<int>(n, -1));
    queue<tuple<int, int, int>> q;
    q.push({0, 0, k});
    seen[0][0] = k;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int steps = 0;
    
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y, remaining] = q.front(); q.pop();
            if (x == m - 1 && y == n - 1) return steps;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newK = remaining - grid[nx][ny];
                    if (newK >= 0 && newK > seen[nx][ny]) {
                        seen[nx][ny] = newK;
                        q.push({nx, ny, newK});
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}

// LC 1197: Minimum Knight Moves (BFS with pruning)
int minKnightMoves(int x, int y) {
    x = abs(x); y = abs(y);
    if (x == 0 && y == 0) return 0;
    
    vector<vector<int>> dirs = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    queue<pair<int,int>> q;
    set<pair<int,int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    int steps = 0;
    
    while (!q.empty()) {
        int sz = q.size(); steps++;
        while (sz--) {
            auto [cx, cy] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nx = cx + d[0], ny = cy + d[1];
                if (nx == x && ny == y) return steps;
                if (nx >= -2 && ny >= -2 && nx <= x + 2 && ny <= y + 2 && !visited.count({nx, ny})) {
                    visited.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() { cout << "BFS with state - obstacles and knight moves\n"; return 0; }
