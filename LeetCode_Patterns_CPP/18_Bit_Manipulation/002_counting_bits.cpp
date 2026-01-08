// LC 191: Number of 1 Bits | Pattern: Bit Counting
// Time: O(1) (32 bits) | Space: O(1)
#include <iostream>
#include <cstdint>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) { n &= (n - 1); count++; }  // Clear lowest set bit
    return count;
}

// LC 338: Counting Bits - all numbers 0 to n
vector<int> countBits(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) dp[i] = dp[i >> 1] + (i & 1);
    return dp;
}

int main() {
    cout << "Bits in 11: " << hammingWeight(11) << endl;
    return 0;
}
