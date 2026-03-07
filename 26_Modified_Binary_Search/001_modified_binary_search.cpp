// Modified Binary Search Pattern
// LC 744: Find Smallest Letter Greater | LC 162: Find Peak Element
// LC 540: Single Element in Sorted Array | LC 1095: Find in Mountain Array
#include <iostream>
#include <vector>
using namespace std;

// LC 744: Find Smallest Letter Greater Than Target
char nextGreatestLetter(vector<char>& letters, char target) {
    int lo = 0, hi = letters.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (letters[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return letters[lo % letters.size()];
}

// LC 162: Find Peak Element
int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid + 1]) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// LC 540: Single Element in Sorted Array (all others appear twice)
int singleNonDuplicate(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid % 2 == 1) mid--;  // Ensure mid is even
        if (nums[mid] == nums[mid + 1]) lo = mid + 2;
        else hi = mid;
    }
    return nums[lo];
}

// LC 852: Peak Index in Mountain Array
int peakIndexInMountainArray(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < arr[mid + 1]) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak element at: " << findPeakElement(nums) << endl;
    return 0;
}
