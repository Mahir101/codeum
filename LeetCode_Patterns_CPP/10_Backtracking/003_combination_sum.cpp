// LC 39: Combination Sum | Pattern: Backtracking with Repetition
// Time: O(n^(target/min)) | Space: O(target/min)
// Recognition: "Find combinations summing to target, unlimited use"
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& candidates, int target, int idx, 
               vector<int>& curr, vector<vector<int>>& result) {
    if (target == 0) { result.push_back(curr); return; }
    if (target < 0) return;
    for (int i = idx; i < (int)candidates.size(); i++) {
        curr.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(candidates, target, 0, curr, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    auto combs = combinationSum(candidates, 7);
    cout << "Combinations for target 7: " << combs.size() << " total\n";
    return 0;
}
