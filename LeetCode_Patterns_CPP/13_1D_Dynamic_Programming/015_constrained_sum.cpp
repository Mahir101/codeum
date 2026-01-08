// LC 1425: Constrained Subsequence Sum | LC 1567: Max Length of Positive Product Subarray
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// LC 1425: Constrained Subsequence Sum (DP + Monotonic Deque)
int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    deque<int> dq;  // Store indices of max dp values
    int result = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();
        dp[i] = nums[i] + (dq.empty() ? 0 : max(0, dp[dq.front()]));
        while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
        dq.push_back(i);
        result = max(result, dp[i]);
    }
    return result;
}

// LC 1567: Maximum Length of Subarray With Positive Product
int getMaxLen(vector<int>& nums) {
    int n = nums.size();
    int pos = 0, neg = 0, maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) { pos = neg = 0; }
        else if (nums[i] > 0) { pos++; neg = neg > 0 ? neg + 1 : 0; }
        else { int temp = pos; pos = neg > 0 ? neg + 1 : 0; neg = temp + 1; }
        maxLen = max(maxLen, pos);
    }
    return maxLen;
}

// LC 978: Longest Turbulent Subarray
int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size(), result = 1;
    int inc = 1, dec = 1;  // Length ending at i with inc/dec
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) { inc = dec + 1; dec = 1; }
        else if (arr[i] < arr[i-1]) { dec = inc + 1; inc = 1; }
        else { inc = dec = 1; }
        result = max(result, max(inc, dec));
    }
    return result;
}

int main() {
    vector<int> nums = {10, 2, -10, 5, 20};
    cout << "Constrained sum k=2: " << constrainedSubsetSum(nums, 2) << endl;
    return 0;
}
