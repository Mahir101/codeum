// LC 4Sum | LC 454: 4Sum II | LC 18: 4Sum
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// LC 18: 4Sum (find all unique quadruplets)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue;
            int left = j + 1, right = n - 1;
            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++; right--;
                } else if (sum < target) left++;
                else right--;
            }
        }
    }
    return result;
}

// LC 454: 4Sum II (count pairs from 4 arrays)
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> sumAB;
    for (int a : A) for (int b : B) sumAB[a + b]++;
    int count = 0;
    for (int c : C) for (int d : D) count += sumAB[-(c + d)];
    return count;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    auto result = fourSum(nums, 0);
    cout << "4Sum found: " << result.size() << " quadruplets\n";
    return 0;
}
