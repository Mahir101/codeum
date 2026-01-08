// LC 5: Longest Palindromic Substring | Pattern: Expand from Center
// Time: O(n²) | Space: O(1)
// Recognition: "Find longest palindrome substring in string"
#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size(), start = 0, maxLen = 1;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
        return r - l - 1;
    };
    for (int i = 0; i < n; i++) {
        int len1 = expand(i, i);
        int len2 = expand(i, i + 1);
        int len = max(len1, len2);
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    cout << "Longest palindrome in 'babad': " << longestPalindrome("babad") << endl;
    return 0;
}
