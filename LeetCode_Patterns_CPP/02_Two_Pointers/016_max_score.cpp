// LC 1793: Maximum Score of Good Subarray | LC 1818: Minimum Absolute Sum Difference
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// LC 1793: Maximum Score of Good Subarray (expand from k)
int maximumScore(vector<int>& nums, int k) {
    int left = k, right = k, minVal = nums[k], n = nums.size();
    int maxScore = minVal;
    
    while (left > 0 || right < n - 1) {
        int leftVal = left > 0 ? nums[left - 1] : 0;
        int rightVal = right < n - 1 ? nums[right + 1] : 0;
        if (leftVal >= rightVal) { left--; minVal = min(minVal, nums[left]); }
        else { right++; minVal = min(minVal, nums[right]); }
        maxScore = max(maxScore, minVal * (right - left + 1));
    }
    return maxScore;
}

// LC 1818: Minimum Absolute Sum Difference
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), mod = 1e9 + 7;
    set<int> sorted(nums1.begin(), nums1.end());
    
    long totalDiff = 0, maxImprove = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(nums1[i] - nums2[i]);
        totalDiff += diff;
        
        auto it = sorted.lower_bound(nums2[i]);
        if (it != sorted.end()) maxImprove = max(maxImprove, (long)diff - abs(*it - nums2[i]));
        if (it != sorted.begin()) maxImprove = max(maxImprove, (long)diff - abs(*prev(it) - nums2[i]));
    }
    return (totalDiff - maxImprove) % mod;
}

int main() {
    vector<int> nums = {1, 4, 3, 7, 4, 5};
    cout << "Max score (k=3): " << maximumScore(nums, 3) << endl;
    return 0;
}
