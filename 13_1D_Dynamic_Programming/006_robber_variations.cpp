// LC 213: House Robber II (Circular) | LC 740: Delete and Earn
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// LC 213: House Robber II (circular)
int robRange(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;
    for (int i = start; i <= end; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1; prev1 = curr;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
}

// LC 740: Delete and Earn (transform to house robber)
int deleteAndEarn(vector<int>& nums) {
    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> earn(maxNum + 1, 0);
    for (int n : nums) earn[n] += n;
    int prev2 = 0, prev1 = 0;
    for (int i = 0; i <= maxNum; i++) {
        int curr = max(prev1, prev2 + earn[i]);
        prev2 = prev1; prev1 = curr;
    }
    return prev1;
}

int main() {
    vector<int> nums = {2, 3, 2};
    cout << "Rob circular: " << rob(nums) << endl;
    return 0;
}
