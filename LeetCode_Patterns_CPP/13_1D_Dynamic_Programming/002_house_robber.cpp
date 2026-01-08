// LC 198: House Robber | Pattern: Take or Skip DP
// Time: O(n) | Space: O(1)
// Recognition: "Max sum with no adjacent elements"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Max robbery: " << rob(houses) << endl;
    return 0;
}
