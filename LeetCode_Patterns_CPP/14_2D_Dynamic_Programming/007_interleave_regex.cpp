// LC 97: Interleaving String | LC 10: Regular Expression Matching
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC 97: Interleaving String
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != (int)s3.size()) return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                       (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[m][n];
}

// LC 10: Regular Expression Matching
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 2; j <= n; j += 2)
        if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2] || 
                           ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << "Interleave: " << isInterleave("aab", "axy", "aaxaby") << endl;
    cout << "Regex: " << isMatch("aa", "a*") << endl;
    return 0;
}
