// LC 169: Majority Element
// Pattern: Boyer-Moore Voting Algorithm
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    
    return candidate;
}

// LC 229: Majority Element II (appears > n/3 times)
vector<int> majorityElementII(vector<int>& nums) {
    int c1 = 0, c2 = 0, cnt1 = 0, cnt2 = 0;
    
    for (int num : nums) {
        if (num == c1) cnt1++;
        else if (num == c2) cnt2++;
        else if (cnt1 == 0) { c1 = num; cnt1 = 1; }
        else if (cnt2 == 0) { c2 = num; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }
    
    // Verify candidates
    cnt1 = cnt2 = 0;
    for (int num : nums) {
        if (num == c1) cnt1++;
        else if (num == c2) cnt2++;
    }
    
    vector<int> result;
    int n = nums.size();
    if (cnt1 > n / 3) result.push_back(c1);
    if (cnt2 > n / 3) result.push_back(c2);
    return result;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority element: " << majorityElement(nums) << endl;
    
    vector<int> nums2 = {3, 2, 3};
    auto result = majorityElementII(nums2);
    cout << "Majority II: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
