// LC 167: Two Sum II (Sorted Array)
// Pattern: Two Pointers (Converging)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) return {left + 1, right + 1};
        if (sum < target) left++;
        else right--;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 9);
    cout << "Two Sum II: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
