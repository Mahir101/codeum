// Manacher's Algorithm for Longest Palindromic Substring
// LC 5: Longest Palindromic Substring | LC 647: Palindromic Substrings
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Manacher's Algorithm O(n)
string longestPalindrome(string s) {
    // Transform: "abc" -> "^#a#b#c#$"
    string t = "^#";
    for (char c : s) { t += c; t += '#'; }
    t += '$';
    
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    
    for (int i = 1; i < n - 1; i++) {
        if (i < right) p[i] = min(right - i, p[2 * center - i]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (i + p[i] > right) { center = i; right = i + p[i]; }
    }
    
    int maxLen = 0, maxCenter = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) { maxLen = p[i]; maxCenter = i; }
    }
    return s.substr((maxCenter - maxLen) / 2, maxLen);
}

// LC 5: Expand Around Center O(n^2)
string longestPalindromeExpand(string s) {
    int start = 0, maxLen = 0;
    auto expand = [&](int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) { left--; right++; }
        if (right - left - 1 > maxLen) { maxLen = right - left - 1; start = left + 1; }
    };
    for (int i = 0; i < (int)s.size(); i++) { expand(i, i); expand(i, i + 1); }
    return s.substr(start, maxLen);
}

int main() {
    cout << "Longest palindrome 'babad': " << longestPalindrome("babad") << endl;
    return 0;
}
