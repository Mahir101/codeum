// LC 137: Single Number II | LC 268: Missing Number (XOR)
#include <iostream>
#include <vector>
using namespace std;

// LC 137: Single Number II (every element appears 3 times except one)
int singleNumberII(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int n : nums) {
        ones = (ones ^ n) & ~twos;
        twos = (twos ^ n) & ~ones;
    }
    return ones;
}

// LC 268: Missing Number (XOR approach)
int missingNumber(vector<int>& nums) {
    int xorVal = nums.size();
    for (int i = 0; i < (int)nums.size(); i++) {
        xorVal ^= i ^ nums[i];
    }
    return xorVal;
}

// Swap without temp using XOR
void swapXOR(int& a, int& b) {
    if (&a != &b) { a ^= b; b ^= a; a ^= b; }
}

// Find two missing numbers in [1, n]
vector<int> findTwoMissing(vector<int>& nums, int n) {
    int xorAll = 0;
    for (int i = 1; i <= n; i++) xorAll ^= i;
    for (int num : nums) xorAll ^= num;
    
    int setBit = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (i & setBit) a ^= i;
        else b ^= i;
    }
    for (int num : nums) {
        if (num & setBit) a ^= num;
        else b ^= num;
    }
    return {a, b};
}

int main() {
    vector<int> nums = {2, 2, 3, 2};
    cout << "Single number II: " << singleNumberII(nums) << endl;
    return 0;
}
