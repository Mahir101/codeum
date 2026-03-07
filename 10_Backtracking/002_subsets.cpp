// LC 78: Subsets | Pattern: Include/Exclude Backtracking
// Time: O(2^n) | Space: O(n)
// Recognition: "Generate all subsets (power set)"
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
    result.push_back(curr);
    for (int i = idx; i < (int)nums.size(); i++) {
        curr.push_back(nums[i]);
        backtrack(nums, i + 1, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(nums, 0, curr, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto subs = subsets(nums);
    cout << "Subsets of [1,2,3]: " << subs.size() << " total\n";
    return 0;
}
