// LC 371: Sum Without Plus | LC 268: Missing Number | LC 190: Reverse Bits
#include <iostream>
#include <vector>
using namespace std;

// LC 371: Sum of Two Integers (no + or -)
int getSum(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

// LC 268: Missing Number (XOR)
int missingNumber(vector<int>& nums) {
    int result = nums.size();
    for (int i = 0; i < (int)nums.size(); i++)
        result ^= i ^ nums[i];
    return result;
}

// LC 190: Reverse Bits
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

// LC 7: Reverse Integer
int reverse(int x) {
    int result = 0;
    while (x != 0) {
        int digit = x % 10;
        if (result > INT_MAX / 10 || result < INT_MIN / 10) return 0;
        result = result * 10 + digit;
        x /= 10;
    }
    return result;
}

int main() {
    cout << "Sum without +: " << getSum(1, 2) << endl;
    vector<int> nums = {3, 0, 1};
    cout << "Missing number: " << missingNumber(nums) << endl;
    return 0;
}
