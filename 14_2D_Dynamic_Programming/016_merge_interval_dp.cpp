// LC 1000: Minimum Cost to Merge Stones | LC 1547: Minimum Cost to Cut a Stick
#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

// LC 1000: Minimum Cost to Merge Stones
int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    if ((n - 1) % (k - 1) != 0) return -1;
    
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = k; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int mid = i; mid < j; mid += k - 1) {
                dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
            }
            if ((len - 1) % (k - 1) == 0) {
                dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
    }
    return dp[0][n - 1];
}

// LC 1039: Minimum Score Triangulation of Polygon
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], 
                    dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> stones = {3, 2, 4, 1};
    cout << "Merge cost k=2: " << mergeStones(stones, 2) << endl;
    return 0;
}
