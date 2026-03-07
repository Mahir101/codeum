// LC 862: Shortest Subarray Sum >= K | Monotonic Deque Applications
// LC 1499: Max Value of Equation
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// LC 1499: Max Value of Equation (yi + yj + |xi - xj| where j > i)
// = yi - xi + yj + xj, so find max(yi - xi) for all valid i
int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    deque<pair<int, int>> dq;  // {yi - xi, xi}
    int maxVal = INT_MIN;
    
    for (auto& p : points) {
        int x = p[0], y = p[1];
        while (!dq.empty() && x - dq.front().second > k) dq.pop_front();
        if (!dq.empty()) maxVal = max(maxVal, dq.front().first + x + y);
        while (!dq.empty() && y - x >= dq.back().first) dq.pop_back();
        dq.push_back({y - x, x});
    }
    return maxVal;
}

// Sliding Window Maximum with Deque (LC 239)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// Jump Game VI with Deque (LC 1696)
int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> dp(n);
    dp[0] = nums[0];
    dq.push_back(0);
    for (int i = 1; i < n; i++) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();
        dp[i] = dp[dq.front()] + nums[i];
        while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> points = {{1,3},{2,0},{5,10},{6,-10}};
    cout << "Max equation k=1: " << findMaxValueOfEquation(points, 1) << endl;
    return 0;
}
