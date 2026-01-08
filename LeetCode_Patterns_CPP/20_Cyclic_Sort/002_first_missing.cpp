// LC 41: First Missing Positive | LC 645: Set Mismatch
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// LC 41: First Missing Positive
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < n; i++) if (nums[i] != i + 1) return i + 1;
    return n + 1;
}

// LC 645: Set Mismatch (find duplicate and missing)
vector<int> findErrorNums(vector<int>& nums) {
    int dup = -1, missing = -1;
    for (int i = 0; i < (int)nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) dup = abs(nums[i]);
        else nums[idx] = -nums[idx];
    }
    for (int i = 0; i < (int)nums.size(); i++) if (nums[i] > 0) missing = i + 1;
    return {dup, missing};
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << "First missing: " << firstMissingPositive(nums) << endl;
    return 0;
}
