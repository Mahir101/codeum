// LC 1143: Longest Common Subsequence | Pattern: Two-String DP
// Time: O(m*n) | Space: O(n)
// Recognition: "Longest subsequence common to both strings"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<int> dp(n + 1, 0), prev(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) dp[j] = prev[j-1] + 1;
            else dp[j] = max(dp[j-1], prev[j]);
        }
        swap(dp, prev);
    }
    return prev[n];
}

int main() {
    cout << "LCS 'abcde' and 'ace': " << longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
