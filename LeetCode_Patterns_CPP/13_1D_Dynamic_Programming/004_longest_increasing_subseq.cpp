// LC 300: Longest Increasing Subsequence | Pattern: Patience Sort
// Time: O(n log n) | Space: O(n)
// Recognition: "Longest subsequence where each element > previous"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) tails.push_back(num);
        else *it = num;
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lengthOfLIS(nums) << endl;
    return 0;
}
