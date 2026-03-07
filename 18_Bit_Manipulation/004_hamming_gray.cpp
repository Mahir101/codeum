// LC 477: Total Hamming Distance | LC 461: Hamming Distance
#include <iostream>
#include <vector>
using namespace std;

// LC 461: Hamming Distance (XOR and count bits)
int hammingDistance(int x, int y) {
    int xorVal = x ^ y, count = 0;
    while (xorVal) { count += xorVal & 1; xorVal >>= 1; }
    return count;
}

// LC 477: Total Hamming Distance
int totalHammingDistance(vector<int>& nums) {
    int total = 0, n = nums.size();
    for (int bit = 0; bit < 32; bit++) {
        int ones = 0;
        for (int num : nums) ones += (num >> bit) & 1;
        total += ones * (n - ones);
    }
    return total;
}

// LC 89: Gray Code
vector<int> grayCode(int n) {
    vector<int> result = {0};
    for (int i = 0; i < n; i++) {
        int sz = result.size();
        for (int j = sz - 1; j >= 0; j--)
            result.push_back(result[j] | (1 << i));
    }
    return result;
}

// LC 342: Power of Four
bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
}

int main() {
    cout << "Hamming(1, 4): " << hammingDistance(1, 4) << endl;
    vector<int> nums = {4, 14, 2};
    cout << "Total Hamming: " << totalHammingDistance(nums) << endl;
    return 0;
}
