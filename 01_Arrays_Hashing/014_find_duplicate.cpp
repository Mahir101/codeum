// LC 287: Find the Duplicate Number
// Pattern: Floyd's Cycle Detection (Tortoise and Hare)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // Phase 1: Find intersection point
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Phase 2: Find cycle entrance
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}

// Alternative: Negative marking (modifies array)
int findDuplicateMarking(vector<int>& nums) {
    for (int num : nums) {
        int idx = abs(num);
        if (nums[idx] < 0) return idx;
        nums[idx] = -nums[idx];
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate: " << findDuplicate(nums) << endl;
    
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Duplicate: " << findDuplicate(nums2) << endl;
    return 0;
}
