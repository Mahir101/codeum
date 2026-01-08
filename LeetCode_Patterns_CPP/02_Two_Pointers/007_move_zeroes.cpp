// LC 283: Move Zeroes
// Pattern: Two Pointers (In-Place Swap)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    cout << "After moving zeroes: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    return 0;
}
