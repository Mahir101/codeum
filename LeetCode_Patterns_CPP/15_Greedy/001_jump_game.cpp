// LC 55: Jump Game | Pattern: Greedy Reachability
// Time: O(n) | Space: O(1)
// Recognition: "Can reach end given jump distances"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

// LC 45: Jump Game II - minimum jumps
int jump(vector<int>& nums) {
    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) { jumps++; end = farthest; }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Can jump: " << canJump(nums) << ", Min jumps: " << jump(nums) << endl;
    return 0;
}
