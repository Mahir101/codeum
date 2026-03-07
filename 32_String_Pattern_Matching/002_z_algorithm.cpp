// Z-Algorithm | LC 1392: Longest Happy Prefix
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Z-Array: z[i] = length of longest substring starting from i that matches prefix
vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

// Pattern matching using Z-algorithm
vector<int> zSearch(const string& text, const string& pattern) {
    string concat = pattern + "$" + text;
    vector<int> z = zFunction(concat);
    vector<int> positions;
    for (int i = pattern.size() + 1; i < (int)concat.size(); i++)
        if (z[i] == (int)pattern.size())
            positions.push_back(i - pattern.size() - 1);
    return positions;
}

// LC 1392: Longest Happy Prefix
string longestPrefix(string s) {
    vector<int> z = zFunction(s);
    int n = s.size(), maxLen = 0;
    for (int i = 1; i < n; i++)
        if (i + z[i] == n) maxLen = max(maxLen, z[i]);
    return s.substr(0, maxLen);
}

int main() {
    cout << "Longest happy prefix of 'level': " << longestPrefix("level") << endl;
    return 0;
}
