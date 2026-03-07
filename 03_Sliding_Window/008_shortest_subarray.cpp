// LC 862: Shortest Subarray with Sum at Least K | LC 1438: Longest Continuous Subarray
#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

// LC 862: Shortest Subarray with Sum >= K (with negatives!)
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    
    deque<int> dq;
    int minLen = n + 1;
    
    for (int i = 0; i <= n; i++) {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            minLen = min(minLen, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    return minLen <= n ? minLen : -1;
}

// LC 1438: Longest Continuous Subarray With Absolute Diff <= Limit
int longestSubarray(vector<int>& nums, int limit) {
    map<int, int> window;
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        window[nums[right]]++;
        while (window.rbegin()->first - window.begin()->first > limit) {
            if (--window[nums[left]] == 0) window.erase(nums[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {2, -1, 2};
    cout << "Shortest subarray >= 3: " << shortestSubarray(nums, 3) << endl;
    return 0;
}
