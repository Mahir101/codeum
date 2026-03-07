// LC 1335: Minimum Difficulty of Job Schedule | LC 1014: Best Sightseeing Pair
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 1335: Minimum Difficulty of Job Schedule
int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d) return -1;
    
    vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;
    
    for (int day = 1; day <= d; day++) {
        for (int j = day; j <= n; j++) {
            int maxDiff = 0;
            for (int k = j; k >= day; k--) {
                maxDiff = max(maxDiff, jobDifficulty[k - 1]);
                if (dp[day - 1][k - 1] != INT_MAX)
                    dp[day][j] = min(dp[day][j], dp[day - 1][k - 1] + maxDiff);
            }
        }
    }
    return dp[d][n];
}

// LC 1014: Best Sightseeing Pair (values[i] + values[j] + i - j)
int maxScoreSightseeingPair(vector<int>& values) {
    int maxI = values[0] + 0;  // values[i] + i
    int result = 0;
    for (int j = 1; j < (int)values.size(); j++) {
        result = max(result, maxI + values[j] - j);
        maxI = max(maxI, values[j] + j);
    }
    return result;
}

// LC 918: Maximum Sum Circular Subarray
int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0, maxSum = INT_MIN, minSum = INT_MAX;
    int currMax = 0, currMin = 0;
    for (int n : nums) {
        currMax = max(currMax + n, n);
        maxSum = max(maxSum, currMax);
        currMin = min(currMin + n, n);
        minSum = min(minSum, currMin);
        totalSum += n;
    }
    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
}

int main() {
    vector<int> jobs = {6, 5, 4, 3, 2, 1};
    cout << "Min difficulty d=2: " << minDifficulty(jobs, 2) << endl;
    return 0;
}
