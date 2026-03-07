// LC 473: Matchsticks to Square | LC 698: Partition to K Equal Subsets
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// LC 473: Matchsticks to Square
bool makesquare(vector<int>& matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4 != 0) return false;
    int side = sum / 4;
    sort(matchsticks.rbegin(), matchsticks.rend());
    vector<int> sides(4, 0);
    
    function<bool(int)> backtrack = [&](int idx) -> bool {
        if (idx == (int)matchsticks.size()) return true;
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= side) {
                sides[i] += matchsticks[idx];
                if (backtrack(idx + 1)) return true;
                sides[i] -= matchsticks[idx];
            }
            if (sides[i] == 0) break;  // Pruning
        }
        return false;
    };
    return backtrack(0);
}

// LC 698: Partition to K Equal Sum Subsets
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    int target = sum / k;
    sort(nums.rbegin(), nums.rend());
    if (nums[0] > target) return false;
    
    vector<int> buckets(k, 0);
    function<bool(int)> backtrack = [&](int idx) -> bool {
        if (idx == (int)nums.size()) return true;
        for (int i = 0; i < k; i++) {
            if (buckets[i] + nums[idx] <= target) {
                buckets[i] += nums[idx];
                if (backtrack(idx + 1)) return true;
                buckets[i] -= nums[idx];
            }
            if (buckets[i] == 0) break;
        }
        return false;
    };
    return backtrack(0);
}

int main() {
    vector<int> matches = {1,1,2,2,2};
    cout << "Can make square: " << makesquare(matches) << endl;
    return 0;
}
