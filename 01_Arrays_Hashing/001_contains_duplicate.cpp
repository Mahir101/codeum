// LC 217: Contains Duplicate
// Pattern: Hash Set
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << "Contains duplicate: " << (containsDuplicate(nums) ? "Yes" : "No") << endl;
    return 0;
}
