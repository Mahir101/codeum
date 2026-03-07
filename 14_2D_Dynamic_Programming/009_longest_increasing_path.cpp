// LC 329: Longest Increasing Path in Matrix | Pattern: DFS + Memoization
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int m, n;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != 0) return memo[i][j];
        memo[i][j] = 1;
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && 
                matrix[ni][nj] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], 1 + dfs(matrix, memo, ni, nj));
            }
        }
        return memo[i][j];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxLen = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                maxLen = max(maxLen, dfs(matrix, memo, i, j));
        return maxLen;
    }
};

int main() {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    Solution sol;
    cout << "Longest increasing path: " << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}
