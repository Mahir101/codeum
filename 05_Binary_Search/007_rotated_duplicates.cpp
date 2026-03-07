// LC 81: Search Rotated II | LC 154: Find Min Rotated II (with duplicates)
#include <iostream>
#include <vector>
using namespace std;

// LC 81: Search in Rotated Sorted Array II (duplicates)
bool search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return true;
        
        // Handle duplicates
        if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
            lo++; hi--;
        } else if (nums[lo] <= nums[mid]) {
            if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return false;
}

// LC 154: Find Minimum in Rotated Sorted Array II (duplicates)
int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else if (nums[mid] < nums[hi]) hi = mid;
        else hi--;  // Handle duplicates
    }
    return nums[lo];
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    cout << "Search 0: " << search(nums, 0) << endl;
    cout << "Find min: " << findMin(nums) << endl;
    return 0;
}
