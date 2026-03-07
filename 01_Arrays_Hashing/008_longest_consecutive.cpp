// LC 128: Longest Consecutive Sequence
// Pattern: Hash Set + Sequence Start Detection
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;
    
    for (int num : numSet) {
        // Only start counting from sequence start
        if (!numSet.count(num - 1)) {
            int length = 1;
            while (numSet.count(num + length)) {
                length++;
            }
            longest = max(longest, length);
        }
    }
    
    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive: " << longestConsecutive(nums) << endl;
    return 0;
}
