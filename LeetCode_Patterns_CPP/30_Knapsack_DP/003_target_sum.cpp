// LC 494: Target Sum | LC 474: Ones and Zeroes
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 494: Target Sum (count ways to reach target with + and -)
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int n : nums) sum += n;
    if (target > sum || target < -sum || (sum + target) % 2) return 0;
    
    int posSum = (sum + target) / 2;
    vector<int> dp(posSum + 1, 0);
    dp[0] = 1;
    for (int n : nums)
        for (int j = posSum; j >= n; j--)
            dp[j] += dp[j - n];
    return dp[posSum];
}

// LC 474: Ones and Zeroes (2D knapsack)
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (auto& s : strs) {
        int zeros = count(s.begin(), s.end(), '0');
        int ones = s.size() - zeros;
        
        for (int i = m; i >= zeros; i--)
            for (int j = n; j >= ones; j--)
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }
    return dp[m][n];
}

// Count Subsets with Given Sum
int countSubsets(vector<int>& nums, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int n : nums)
        for (int j = sum; j >= n; j--)
            dp[j] += dp[j - n];
    return dp[sum];
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << "Target sum ways: " << findTargetSumWays(nums, 3) << endl;
    return 0;
}
