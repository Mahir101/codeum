// LC 41: First Missing Positive
// Pattern: Cyclic Sort / Index as Hash
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    // Place each number at its correct index (1 at index 0, 2 at index 1, etc.)
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    // Find first missing
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << "First missing positive: " << firstMissingPositive(nums) << endl;
    
    vector<int> nums2 = {1, 2, 0};
    cout << "First missing positive: " << firstMissingPositive(nums2) << endl;
    return 0;
}
