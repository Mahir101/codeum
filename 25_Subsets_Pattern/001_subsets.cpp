// Subsets Pattern - Generate all subsets/combinations
// LC 78: Subsets | LC 90: Subsets II | LC 784: Letter Case Permutation
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LC 78: All Subsets (BFS approach)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    for (int num : nums) {
        int n = result.size();
        for (int i = 0; i < n; i++) {
            vector<int> subset = result[i];
            subset.push_back(num);
            result.push_back(subset);
        }
    }
    return result;
}

// LC 90: Subsets with Duplicates
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = {{}};
    int start = 0, end = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        start = (i > 0 && nums[i] == nums[i-1]) ? end : 0;
        end = result.size();
        for (int j = start; j < end; j++) {
            vector<int> subset = result[j];
            subset.push_back(nums[i]);
            result.push_back(subset);
        }
    }
    return result;
}

// LC 784: Letter Case Permutation
vector<string> letterCasePermutation(string s) {
    vector<string> result = {""};
    for (char c : s) {
        int n = result.size();
        for (int i = 0; i < n; i++) {
            if (isalpha(c)) {
                result.push_back(result[i] + (char)toupper(c));
                result[i] += tolower(c);
            } else {
                result[i] += c;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << "Subsets count: " << subsets(nums).size() << endl;
    return 0;
}
