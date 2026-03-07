// LC 1539: Kth Missing Positive | LC 41: First Missing Positive
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// LC 1539: Kth Missing Positive Number
int findKthPositive(vector<int>& arr, int k) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k) lo = mid + 1;
        else hi = mid;
    }
    return lo + k;
}

// LC 41: First Missing Positive (revisited with counting sort)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int& num : nums) if (num <= 0 || num > n) num = n + 1;
    for (int i = 0; i < n; i++) {
        int val = abs(nums[i]);
        if (val <= n && nums[val - 1] > 0) nums[val - 1] = -nums[val - 1];
    }
    for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
    return n + 1;
}

// Count elements in range [lo, hi]
int countInRange(vector<int>& nums, int lo, int hi) {
    int count = 0;
    for (int n : nums) if (n >= lo && n <= hi) count++;
    return count;
}

// Find duplicate in [1, n] with O(1) space using binary search on count
int findDuplicateBS(vector<int>& nums) {
    int n = nums.size() - 1;
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (countInRange(nums, lo, mid) > mid - lo + 1) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    cout << "5th missing: " << findKthPositive(arr, 5) << endl;
    return 0;
}
