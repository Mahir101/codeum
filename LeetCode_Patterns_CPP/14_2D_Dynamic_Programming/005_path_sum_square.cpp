// LC 64: Minimum Path Sum | LC 221: Maximal Square
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 64: Minimum Path Sum
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 1; i < m; i++) grid[i][0] += grid[i-1][0];
    for (int j = 1; j < n; j++) grid[0][j] += grid[0][j-1];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
    return grid[m-1][n-1];
}

// LC 221: Maximal Square
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), maxSide = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i-1][j-1] == '1') {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << "Min path sum: " << minPathSum(grid) << endl;
    return 0;
}
