// LC 312: Burst Balloons | LC 1547: Minimum Cost to Cut a Stick
// Pattern: Interval DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 312: Burst Balloons
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> balloons(n + 2, 1);
    for (int i = 0; i < n; i++) balloons[i + 1] = nums[i];
    n += 2;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) {
        for (int left = 0; left + len < n; left++) {
            int right = left + len;
            for (int k = left + 1; k < right; k++) {
                dp[left][right] = max(dp[left][right],
                    dp[left][k] + dp[k][right] + 
                    balloons[left] * balloons[k] * balloons[right]);
            }
        }
    }
    return dp[0][n - 1];
}

// LC 1547: Minimum Cost to Cut a Stick
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    
    for (int len = 2; len < m; len++) {
        for (int i = 0; i + len < m; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }
    }
    return dp[0][m - 1];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << "Max coins: " << maxCoins(nums) << endl;
    return 0;
}
