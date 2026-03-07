/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║  BINARY SEARCH: Classic + Variations                                      ║
 * ║  LeetCode 704, 35, 34 | Core Pattern                                      ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🎯 PATTERN RECOGNITION CUES                                             │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ ✓ Sorted array / monotonic property                                     │
 * │ ✓ "Find first/last occurrence"                                          │
 * │ ✓ "Minimize/maximize X such that condition holds"                       │
 * │ ✓ O(n) brute force can be reduced to O(log n)                           │
 * │ ✓ Search space can be divided in half                                   │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🧠 BRAIN TRAINING: Binary Search Templates                              │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ TEMPLATE 1: Find exact value (classic)                                  │
 * │   while (lo <= hi) { if (arr[mid] == target) return mid; }              │
 * │                                                                         │
 * │ TEMPLATE 2: Find leftmost (lower_bound)                                 │
 * │   while (lo < hi) { if (arr[mid] < target) lo = mid+1; else hi = mid; } │
 * │                                                                         │
 * │ TEMPLATE 3: Find rightmost (upper_bound - 1)                            │
 * │   while (lo < hi) { if (arr[mid] <= target) lo = mid+1; else hi = mid; }│
 * └─────────────────────────────────────────────────────────────────────────┘
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // LC 704: Basic Binary Search
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;  // Avoid overflow
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
    
    // LC 35: Search Insert Position (Lower Bound)
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    
    // LC 34: Find First and Last Position
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) return {-1, -1};
        return {first, findLast(nums, target)};
    }
    
private:
    int findFirst(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, result = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                result = mid;
                hi = mid - 1;  // Continue searching left
            } else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return result;
    }
    
    int findLast(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, result = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                result = mid;
                lo = mid + 1;  // Continue searching right
            } else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return result;
    }
};

/*
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ ⚠️ COMMON PITFALLS                                                      │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ 1. Integer overflow: use lo + (hi - lo) / 2, not (lo + hi) / 2         │
 * │ 2. Infinite loop: ensure search space shrinks each iteration           │
 * │ 3. Off-by-one: test with [1], [1,2], [1,2,3] edge cases                │
 * │ 4. Choosing template: lo <= hi vs lo < hi depends on use case          │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

int main() {
    Solution sol;
    
    cout << "Pattern: BINARY SEARCH\n";
    cout << "======================\n\n";
    
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << "Array: [-1,0,3,5,9,12]\n\n";
    
    cout << "Search 9: index " << sol.search(nums, 9) << "\n";
    cout << "Search 2: index " << sol.search(nums, 2) << "\n";
    cout << "Insert position of 5: " << sol.searchInsert(nums, 5) << "\n";
    cout << "Insert position of 2: " << sol.searchInsert(nums, 2) << "\n";
    
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    auto range = sol.searchRange(nums2, 8);
    cout << "\nFind range of 8 in [5,7,7,8,8,10]: [" 
         << range[0] << "," << range[1] << "]\n";
    
    return 0;
}
