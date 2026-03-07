// LC 416: Partition Equal Subset Sum | Pattern: 0/1 Knapsack
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

// LC 494: Target Sum (count ways)
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;
    int positiveSum = (sum + target) / 2;
    vector<int> dp(positiveSum + 1, 0);
    dp[0] = 1;
    for (int num : nums) {
        for (int j = positiveSum; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    return dp[positiveSum];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << canPartition(nums) << endl;
    return 0;
}
