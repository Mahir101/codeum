// LC 1312: Min Insertions Palindrome | LC 97: Interleaving String
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC 1312: Minimum Insertion Steps to Make Palindrome
int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

// LC 97: Interleaving String
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != (int)s3.size()) return false;
    
    vector<bool> dp(n + 1, false);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) dp[j] = true;
            else if (i == 0) dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
            else if (j == 0) dp[j] = dp[j] && s1[i-1] == s3[i-1];
            else dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[n];
}

// LC 1278: Palindrome Partitioning III
int palindromePartition(string s, int k) {
    int n = s.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            cost[i][j] = cost[i+1][j-1] + (s[i] != s[j]);
        }
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            for (int l = j - 1; l < i; l++) {
                dp[i][j] = min(dp[i][j], dp[l][j-1] + cost[l][i-1]);
            }
        }
    }
    return dp[n][k];
}

int main() {
    cout << "Min insertions 'mbadm': " << minInsertions("mbadm") << endl;
    cout << "Interleave: " << isInterleave("aab", "axy", "aaxaby") << endl;
    return 0;
}
