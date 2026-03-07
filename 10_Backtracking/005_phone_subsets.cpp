// LC 17: Letter Combinations | LC 90: Subsets II (with duplicates)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LC 17: Letter Combinations of Phone Number
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};
    for (char d : digits) {
        vector<string> temp;
        for (string& s : result)
            for (char c : mapping[d - '0'])
                temp.push_back(s + c);
        result = temp;
    }
    return result;
}

// LC 90: Subsets II (with duplicates)
void subsetsWithDupHelper(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
    result.push_back(curr);
    for (int i = idx; i < (int)nums.size(); i++) {
        if (i > idx && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        subsetsWithDupHelper(nums, i + 1, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> curr;
    subsetsWithDupHelper(nums, 0, curr, result);
    return result;
}

int main() {
    auto combos = letterCombinations("23");
    cout << "Phone combos for '23': " << combos.size() << endl;
    return 0;
}
