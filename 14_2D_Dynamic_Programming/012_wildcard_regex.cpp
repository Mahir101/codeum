// LC 44: Wildcard Matching | LC 10: Regular Expression
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC 44: Wildcard Matching (? = single char, * = any sequence)
bool isMatchWildcard(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++)
        if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*')
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else if (p[j-1] == '?' || s[i-1] == p[j-1])
                dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[m][n];
}

// LC 10: Regular Expression Matching (. = any char, * = zero or more of prev)
bool isMatchRegex(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 2; j <= n; j += 2)
        if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2] ||  // Zero occurrences
                           ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);  // One+ occurrences
            } else if (p[j-1] == '.' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << "Wildcard 'adceb' '*a*b': " << isMatchWildcard("adceb", "*a*b") << endl;
    cout << "Regex 'aa' 'a*': " << isMatchRegex("aa", "a*") << endl;
    return 0;
}
