// LC 26: Remove Duplicates from Sorted Array
// Pattern: Two Pointers (Fast/Slow - In-Place)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int slow = 0;
    for (int fast = 1; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

// LC 80: Remove Duplicates II (allow at most 2)
int removeDuplicatesII(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int slow = 2;
    for (int fast = 2; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow - 2]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len = removeDuplicates(nums);
    cout << "After removing duplicates: ";
    for (int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
