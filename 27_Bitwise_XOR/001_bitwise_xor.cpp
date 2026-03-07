// Bitwise XOR Pattern
// LC 136: Single Number | LC 260: Single Number III | LC 1009: Complement
#include <iostream>
#include <vector>
using namespace std;

// LC 136: Single Number (one element appears once, others twice)
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

// LC 260: Two elements appear once (find both)
vector<int> singleNumberIII(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) xorAll ^= num;
    int diffBit = xorAll & (-xorAll);  // Rightmost set bit
    int a = 0, b = 0;
    for (int num : nums) {
        if (num & diffBit) a ^= num;
        else b ^= num;
    }
    return {a, b};
}

// LC 1009: Complement of Base 10 Integer
int bitwiseComplement(int n) {
    if (n == 0) return 1;
    int mask = 1;
    while (mask < n) mask = (mask << 1) | 1;
    return n ^ mask;
}

// Flip Image (LC 832)
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto& row : A) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int temp = row[left] ^ 1;
            row[left++] = row[right] ^ 1;
            row[right--] = temp;
        }
    }
    return A;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    auto result = singleNumberIII(nums);
    cout << "Two single: " << result[0] << ", " << result[1] << endl;
    return 0;
}
