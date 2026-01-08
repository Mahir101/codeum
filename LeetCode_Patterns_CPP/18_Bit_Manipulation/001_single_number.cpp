// LC 136: Single Number | Pattern: XOR Properties
// Time: O(n) | Space: O(1)
// Recognition: "Find unique element among duplicates"
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

// LC 137: Single Number II (every element 3 times except one)
int singleNumberII(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }
    return ones;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number: " << singleNumber(nums) << endl;
    return 0;
}
