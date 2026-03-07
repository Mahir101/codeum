// Prefix Sum Pattern
// LC 303: Range Sum Query | LC 304: 2D Range Sum | LC 560: Subarray Sum Equals K
// LC 523: Continuous Subarray Sum | LC 974: Subarray Sums Divisible by K
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 303: Range Sum Query - Immutable
class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); i++) prefix[i + 1] = prefix[i] + nums[i];
    }
    int sumRange(int left, int right) { return prefix[right + 1] - prefix[left]; }
};

// LC 560: Subarray Sum Equals K
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount; prefixCount[0] = 1;
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixCount.count(sum - k)) count += prefixCount[sum - k];
        prefixCount[sum]++;
    }
    return count;
}

// LC 974: Subarray Sums Divisible by K
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remainderCount; remainderCount[0] = 1;
    int prefixSum = 0, count = 0;
    for (int num : nums) {
        prefixSum = ((prefixSum + num) % k + k) % k;
        count += remainderCount[prefixSum]++;
    }
    return count;
}

// LC 238: Product Except Self (prefix + suffix product)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    int left = 1, right = 1;
    for (int i = 0; i < n; i++) { result[i] *= left; left *= nums[i]; }
    for (int i = n - 1; i >= 0; i--) { result[i] *= right; right *= nums[i]; }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << "Subarrays with sum 2: " << subarraySum(nums, 2) << endl;
    return 0;
}
