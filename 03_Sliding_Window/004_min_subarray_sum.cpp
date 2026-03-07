// LC 209: Min Size Subarray Sum | LC 713: Subarray Product Less Than K
#include <iostream>
#include <vector>
using namespace std;

// LC 209: Minimum Size Subarray Sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, minLen = INT_MAX;
    for (int right = 0; right < (int)nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

// LC 713: Subarray Product < K
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    int left = 0, prod = 1, count = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        prod *= nums[right];
        while (prod >= k) prod /= nums[left++];
        count += right - left + 1;
    }
    return count;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << "Min subarray sum >= 7: " << minSubArrayLen(7, nums) << endl;
    return 0;
}
