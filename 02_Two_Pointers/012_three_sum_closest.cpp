// LC 16: 3Sum Closest
// Pattern: Sort + Two Pointers with Closest Tracking
// Time: O(n²) | Space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }
            if (sum < target) left++;
            else if (sum > target) right--;
            else return target;
        }
    }
    return closest;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    cout << "3Sum closest to 1: " << threeSumClosest(nums, 1) << endl;
    return 0;
}
