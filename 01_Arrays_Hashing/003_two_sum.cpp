// LC 1: Two Sum
// Pattern: Hash Map Complement
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 9);
    cout << "Two Sum [2,7,11,15] target=9: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
