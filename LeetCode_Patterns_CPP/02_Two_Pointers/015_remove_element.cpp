// LC 27: Remove Element
// Pattern: Two Pointers (In-Place Removal)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

// Alternative: swap with end (when removals are rare)
int removeElementSwap(vector<int>& nums, int val) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            n--;
        } else {
            i++;
        }
    }
    return n;
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int len = removeElement(nums, 3);
    cout << "After removing 3: ";
    for (int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
