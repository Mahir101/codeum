// LC 552: Student Attendance Record II | LC 576: Out of Boundary Paths
#include <iostream>
#include <vector>
using namespace std;

// LC 552: Student Attendance Record II (DP with states)
int checkRecord(int n) {
    int mod = 1e9 + 7;
    // dp[i][a][l] = records of length i, a absences, ending with l consecutive lates
    vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(2, vector<long>(3, 0)));
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 2; a++) {
            for (int l = 0; l < 3; l++) {
                if (dp[i][a][l] == 0) continue;
                // Present
                dp[i+1][a][0] = (dp[i+1][a][0] + dp[i][a][l]) % mod;
                // Absent
                if (a < 1) dp[i+1][a+1][0] = (dp[i+1][a+1][0] + dp[i][a][l]) % mod;
                // Late
                if (l < 2) dp[i+1][a][l+1] = (dp[i+1][a][l+1] + dp[i][a][l]) % mod;
            }
        }
    }
    
    long result = 0;
    for (int a = 0; a < 2; a++)
        for (int l = 0; l < 3; l++)
            result = (result + dp[n][a][l]) % mod;
    return result;
}

// LC 576: Out of Boundary Paths
int findPaths(int m, int n, int maxMove, int startRow, int startCol) {
    int mod = 1e9 + 7;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[startRow][startCol] = 1;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    long result = 0;
    
    for (int move = 0; move < maxMove; move++) {
        vector<vector<int>> newDp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        result = (result + dp[i][j]) % mod;
                    else
                        newDp[ni][nj] = (newDp[ni][nj] + dp[i][j]) % mod;
                }
            }
        }
        dp = newDp;
    }
    return result;
}

int main() {
    cout << "Attendance n=2: " << checkRecord(2) << endl;
    cout << "Paths 2x2, 2 moves: " << findPaths(2, 2, 2, 0, 0) << endl;
    return 0;
}
