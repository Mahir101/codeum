// 0/1 Knapsack Pattern
// LC 416: Partition Equal Subset Sum | LC 494: Target Sum
// LC 474: Ones and Zeroes | LC 1049: Last Stone Weight II
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Classic 0/1 Knapsack
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[capacity];
}

// LC 416: Partition Equal Subset Sum
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

// LC 1049: Last Stone Weight II (minimize difference)
int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int stone : stones) {
        for (int j = target; j >= stone; j--) {
            dp[j] = dp[j] || dp[j - stone];
        }
    }
    for (int j = target; j >= 0; j--) {
        if (dp[j]) return sum - 2 * j;
    }
    return sum;
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can partition: " << canPartition(nums) << endl;
    return 0;
}
