// LC 1239: Maximum Length Concatenated String | LC 526: Beautiful Arrangement
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 1239: Max length of unique char concatenation
int maxLength(vector<string>& arr) {
    vector<int> masks;
    for (auto& s : arr) {
        int mask = 0; bool valid = true;
        for (char c : s) {
            int bit = 1 << (c - 'a');
            if (mask & bit) { valid = false; break; }
            mask |= bit;
        }
        if (valid) masks.push_back(mask);
    }
    
    int result = 0;
    function<void(int, int, int)> backtrack = [&](int idx, int currMask, int len) {
        result = max(result, len);
        for (int i = idx; i < (int)masks.size(); i++) {
            if ((currMask & masks[i]) == 0) {
                backtrack(i + 1, currMask | masks[i], len + __builtin_popcount(masks[i]));
            }
        }
    };
    backtrack(0, 0, 0);
    return result;
}

// LC 526: Beautiful Arrangement
int countArrangement(int n) {
    int count = 0;
    vector<bool> used(n + 1, false);
    function<void(int)> backtrack = [&](int pos) {
        if (pos > n) { count++; return; }
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                backtrack(pos + 1);
                used[i] = false;
            }
        }
    };
    backtrack(1);
    return count;
}

int main() {
    vector<string> arr = {"un", "iq", "ue"};
    cout << "Max length: " << maxLength(arr) << endl;
    cout << "Beautiful(3): " << countArrangement(3) << endl;
    return 0;
}
