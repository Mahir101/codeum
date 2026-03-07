// LC 46: Permutations | Pattern: Backtracking
// Time: O(n!) | Space: O(n)
// Recognition: "Generate all arrangements of elements"
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == (int)nums.size()) { result.push_back(nums); return; }
    for (int i = start; i < (int)nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto perms = permute(nums);
    cout << "Permutations of [1,2,3]: " << perms.size() << " total\n";
    return 0;
}
