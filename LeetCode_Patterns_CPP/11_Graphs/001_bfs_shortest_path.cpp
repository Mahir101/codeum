/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║  GRAPH: BFS - Shortest Path in Unweighted Graph                           ║
 * ║  Core Pattern for Level-Order Problems                                    ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🎯 PATTERN RECOGNITION CUES                                             │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ ✓ "Shortest path" in UNWEIGHTED graph → BFS                             │
 * │ ✓ "Minimum moves/steps"                                                 │
 * │ ✓ "Level order traversal"                                               │
 * │ ✓ Need to explore all neighbors before going deeper                     │
 * │ ✓ Multi-source simultaneous expansion (rotten oranges)                  │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🧠 BRAIN TRAINING: BFS Template                                         │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ 1. Initialize queue with starting node(s)                               │
 * │ 2. Mark visited (BEFORE or AFTER adding to queue - be consistent!)      │
 * │ 3. Process level by level (optional: track level number)                │
 * │ 4. For each node: explore all neighbors, add unvisited to queue         │
 * │                                                                         │
 * │ BFS vs DFS:                                                             │
 * │ • BFS = Queue (FIFO) = Level by level = Shortest path                   │
 * │ • DFS = Stack (LIFO) = Go deep first = Path finding                     │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // LC 994: Rotting Oranges (Multi-source BFS)
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Step 1: Add all rotten oranges to queue (multi-source)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        
        if (fresh == 0) return 0;
        
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int minutes = 0;
        
        // Step 2: BFS level by level
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            
            if (rotted) minutes++;
        }
        
        return fresh == 0 ? minutes : -1;
    }
    
    // LC 127: Word Ladder (BFS for shortest transformation)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) return steps;
                
                // Try all possible one-char transformations
                for (int j = 0; j < (int)word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (dict.count(word)) {
                            q.push(word);
                            dict.erase(word);  // Mark visited
                        }
                    }
                    word[j] = original;
                }
            }
            steps++;
        }
        
        return 0;
    }
    
    // LC 200: Number of Islands (BFS version)
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';  // Mark visited
                    
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        
                        for (auto& d : dirs) {
                            int nx = x + d[0], ny = y + d[1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                                grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};

/*
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 📚 BFS PROBLEM CATEGORIES                                               │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ 1. Shortest Path: Word Ladder, Jump Game III, Open the Lock            │
 * │ 2. Multi-source: Rotting Oranges, Walls and Gates, 01 Matrix           │
 * │ 3. Level Order: Binary Tree Level Order, Zigzag Traversal              │
 * │ 4. Connected Components: Number of Islands, Flood Fill                  │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

int main() {
    Solution sol;
    
    cout << "Pattern: BFS (Shortest Path in Unweighted Graph)\n";
    cout << "================================================\n\n";
    
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Rotting Oranges: " << sol.orangesRotting(grid) << " minutes\n\n";
    
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << "Word Ladder 'hit' to 'cog': " 
         << sol.ladderLength("hit", "cog", wordList) << " steps\n";
    
    return 0;
}
