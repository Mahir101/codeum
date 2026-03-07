// LC 560: Subarray Sum Equals K
// Pattern: Prefix Sum + Hash Map
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;  // Empty prefix
    
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        // If (sum - k) exists in map, we found subarrays
        if (prefixCount.count(sum - k)) {
            count += prefixCount[sum - k];
        }
        prefixCount[sum]++;
    }
    
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << "Subarrays with sum 2: " << subarraySum(nums, 2) << endl;
    
    vector<int> nums2 = {1, 2, 3};
    cout << "Subarrays with sum 3: " << subarraySum(nums2, 3) << endl;
    return 0;
}
