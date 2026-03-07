// LC 994: Rotting Oranges | LC 286: Walls and Gates (Multi-source BFS)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

// LC 994: Rotting Oranges
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), fresh = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;
    
    int minutes = 0;
    while (!q.empty() && fresh > 0) {
        minutes++;
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; fresh--;
                    q.push({nx, ny});
                }
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}

// LC 286: Walls and Gates (fill with distance to nearest gate)
void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size(), n = rooms[0].size();
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (rooms[i][j] == 0) q.push({i, j});
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && rooms[nx][ny] == INT_MAX) {
                rooms[nx][ny] = rooms[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Rotting time: " << orangesRotting(grid) << endl;
    return 0;
}
