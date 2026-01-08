// LC 33: Search in Rotated Sorted Array
// Pattern: Modified Binary Search
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[lo] <= nums[mid]) {  // Left half sorted
            if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {  // Right half sorted
            if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

// LC 153: Find Minimum in Rotated Sorted Array
int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else hi = mid;
    }
    return nums[lo];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Search 0: " << search(nums, 0) << endl;
    cout << "Min: " << findMin(nums) << endl;
    return 0;
}
