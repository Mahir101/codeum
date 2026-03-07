// LC 79: Word Search | LC 1091: Shortest Path in Binary Matrix
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int dirs4[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

// LC 79: Word Search
bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j) {
    if (idx == (int)word.size()) return true;
    if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() || 
        board[i][j] != word[idx]) return false;
    char temp = board[i][j]; board[i][j] = '#';
    for (auto& d : dirs4) if (dfs(board, word, idx + 1, i + d[0], j + d[1])) return true;
    board[i][j] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < (int)board.size(); i++)
        for (int j = 0; j < (int)board[0].size(); j++)
            if (dfs(board, word, 0, i, j)) return true;
    return false;
}

// LC 1091: Shortest Path in Binary Matrix (8 directions)
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] || grid[n-1][n-1]) return -1;
    queue<pair<int,int>> q; q.push({0, 0});
    grid[0][0] = 1;
    int path = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            if (x == n-1 && y == n-1) return path;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1; q.push({nx, ny});
                }
            }
        }
        path++;
    }
    return -1;
}

int main() { cout << "Matrix traversal with DFS and BFS\n"; return 0; }
