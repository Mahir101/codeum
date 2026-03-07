/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║  GRAPH: DFS - Path Finding and Exploration                                ║
 * ║  Core Pattern for Deep Traversal Problems                                 ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🎯 PATTERN RECOGNITION CUES                                             │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ ✓ "Find ANY path" (not necessarily shortest)                            │
 * │ ✓ "Explore all possibilities" (backtracking)                            │
 * │ ✓ "Connected components", "Cycle detection"                             │
 * │ ✓ Tree/graph traversals where order matters                             │
 * │ ✓ Problems needing recursion with state                                 │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🧠 BRAIN TRAINING: DFS Templates                                        │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ RECURSIVE (most common):                                                │
 * │   void dfs(node) {                                                      │
 * │       if (base_case) return;                                            │
 * │       mark_visited(node);                                               │
 * │       for (neighbor : neighbors) dfs(neighbor);                         │
 * │   }                                                                     │
 * │                                                                         │
 * │ ITERATIVE (with explicit stack):                                        │
 * │   stack.push(start);                                                    │
 * │   while (!stack.empty()) {                                              │
 * │       node = stack.pop();                                               │
 * │       if (visited) continue;                                            │
 * │       process(node);                                                    │
 * │       for (neighbor) stack.push(neighbor);                              │
 * │   }                                                                     │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // LC 200: Number of Islands (DFS version)
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfsIsland(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    // LC 695: Max Area of Island
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfsArea(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
    // LC 79: Word Search
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfsWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // LC 417: Pacific Atlantic Water Flow
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS from ocean edges
        for (int i = 0; i < m; i++) {
            dfsOcean(heights, pacific, i, 0);
            dfsOcean(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfsOcean(heights, pacific, 0, j);
            dfsOcean(heights, atlantic, m - 1, j);
        }
        
        // Find cells reaching both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void dfsIsland(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        
        grid[i][j] = '0';  // Mark visited
        for (auto& d : dirs) {
            dfsIsland(grid, i + d[0], j + d[1]);
        }
    }
    
    int dfsArea(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        
        grid[i][j] = 0;
        int area = 1;
        for (auto& d : dirs) {
            area += dfsArea(grid, i + d[0], j + d[1]);
        }
        return area;
    }
    
    bool dfsWord(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        if (idx == (int)word.size()) return true;
        
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';  // Mark visited
        
        for (auto& d : dirs) {
            if (dfsWord(board, word, idx + 1, i + d[0], j + d[1])) {
                return true;
            }
        }
        
        board[i][j] = temp;  // Backtrack
        return false;
    }
    
    void dfsOcean(vector<vector<int>>& heights, vector<vector<bool>>& reachable,
                  int i, int j) {
        int m = heights.size(), n = heights[0].size();
        reachable[i][j] = true;
        
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                !reachable[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfsOcean(heights, reachable, ni, nj);
            }
        }
    }
};

int main() {
    Solution sol;
    
    cout << "Pattern: DFS (Deep Exploration)\n";
    cout << "================================\n\n";
    
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << "Word Search 'ABCCED': " << (sol.exist(board, "ABCCED") ? "Found" : "Not found") << "\n";
    cout << "Word Search 'SEE': " << (sol.exist(board, "SEE") ? "Found" : "Not found") << "\n";
    
    return 0;
}
