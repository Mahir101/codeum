// LC 417: Pacific Atlantic | LC 130: Surrounded Regions
#include <iostream>
#include <vector>
using namespace std;

int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

// LC 417: Pacific Atlantic Water Flow
void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int i, int j) {
    reachable[i][j] = true;
    for (auto& d : dirs) {
        int ni = i + d[0], nj = j + d[1];
        if (ni >= 0 && ni < (int)heights.size() && nj >= 0 && nj < (int)heights[0].size() &&
            !reachable[ni][nj] && heights[ni][nj] >= heights[i][j])
            dfs(heights, reachable, ni, nj);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n)), atlantic(m, vector<bool>(n));
    for (int i = 0; i < m; i++) { dfs(heights, pacific, i, 0); dfs(heights, atlantic, i, n-1); }
    for (int j = 0; j < n; j++) { dfs(heights, pacific, 0, j); dfs(heights, atlantic, m-1, j); }
    vector<vector<int>> result;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
    return result;
}

// LC 130: Surrounded Regions (flip O not connected to border)
void dfsSurround(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() || board[i][j] != 'O') return;
    board[i][j] = 'T';
    for (auto& d : dirs) dfsSurround(board, i + d[0], j + d[1]);
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) { dfsSurround(board, i, 0); dfsSurround(board, i, n-1); }
    for (int j = 0; j < n; j++) { dfsSurround(board, 0, j); dfsSurround(board, m-1, j); }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = board[i][j] == 'T' ? 'O' : 'X';
}

int main() { cout << "Pacific Atlantic and Surrounded Regions\n"; return 0; }
