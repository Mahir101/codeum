// String Pattern Matching (KMP, Rabin-Karp, Z-Algorithm)
// LC 28: Find Index of First Occurrence | LC 459: Repeated Substring
// LC 214: Shortest Palindrome | LC 1392: Longest Happy Prefix
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// KMP Failure Function (Prefix Table)
vector<int> computeLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) lps[i++] = ++len;
        else if (len > 0) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

// LC 28: KMP Search
int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    vector<int> lps = computeLPS(needle);
    int i = 0, j = 0;
    while (i < (int)haystack.size()) {
        if (haystack[i] == needle[j]) { i++; j++; }
        if (j == (int)needle.size()) return i - j;
        if (i < (int)haystack.size() && haystack[i] != needle[j]) {
            if (j > 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

// LC 459: Repeated Substring Pattern
bool repeatedSubstringPattern(string s) {
    vector<int> lps = computeLPS(s);
    int n = s.size(), len = lps[n - 1];
    return len > 0 && n % (n - len) == 0;
}

// Rabin-Karp Rolling Hash
int rabinKarp(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return -1;
    long long base = 26, mod = 1e9 + 7;
    long long patHash = 0, textHash = 0, power = 1;
    for (int i = 0; i < m; i++) {
        patHash = (patHash * base + pattern[i]) % mod;
        textHash = (textHash * base + text[i]) % mod;
        if (i < m - 1) power = (power * base) % mod;
    }
    for (int i = 0; i <= n - m; i++) {
        if (patHash == textHash && text.substr(i, m) == pattern) return i;
        if (i < n - m) {
            textHash = ((textHash - text[i] * power % mod + mod) * base + text[i + m]) % mod;
        }
    }
    return -1;
}

int main() {
    cout << "KMP: " << strStr("hello", "ll") << endl;
    cout << "Rabin-Karp: " << rabinKarp("hello", "ll") << endl;
    return 0;
}
