// LC 200: Number of Islands | LC 130: Surrounded Regions | LC 695: Max Area
#include <iostream>
#include <vector>
using namespace std;

int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] != '1') return;
    grid[i][j] = '0';
    for (auto& d : dirs) dfs(grid, i + d[0], j + d[1]);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < (int)grid.size(); i++)
        for (int j = 0; j < (int)grid[0].size(); j++)
            if (grid[i][j] == '1') { dfs(grid, i, j); count++; }
    return count;
}

// LC 695: Max Area of Island
int dfsArea(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] != 1) return 0;
    grid[i][j] = 0;
    int area = 1;
    for (auto& d : dirs) area += dfsArea(grid, i + d[0], j + d[1]);
    return area;
}

int main() { cout << "Island problems - DFS flood fill\n"; return 0; }
