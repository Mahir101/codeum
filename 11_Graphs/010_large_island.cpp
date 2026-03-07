// LC 1293: Grid Obstacles | LC 417: Pacific Atlantic (advanced matrix DFS)
// LC 827: Making A Large Island
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

// LC 827: Making A Large Island
class Solution {
    int m, n;
    
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = id;
        int size = 1;
        for (auto& d : dirs) size += dfs(grid, i + d[0], j + d[1], id);
        return size;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        unordered_map<int, int> islandSize;
        int id = 2;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) islandSize[id] = dfs(grid, i, j, id++);
        
        int maxSize = 0;
        for (auto& [_, size] : islandSize) maxSize = max(maxSize, size);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    for (auto& d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > 1)
                            neighbors.insert(grid[ni][nj]);
                    }
                    int size = 1;
                    for (int id : neighbors) size += islandSize[id];
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;
    }
};

int main() {
    vector<vector<int>> grid = {{1,0},{0,1}};
    Solution sol;
    cout << "Largest island: " << sol.largestIsland(grid) << endl;
    return 0;
}
