// LC 977: Squares of Sorted Array
// Pattern: Two Pointers from Both Ends
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    
    for (int i = n - 1; i >= 0; i--) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[i] = nums[left] * nums[left];
            left++;
        } else {
            result[i] = nums[right] * nums[right];
            right--;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    auto result = sortedSquares(nums);
    cout << "Sorted squares: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
