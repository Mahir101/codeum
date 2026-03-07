// LC 1143: Longest Common Subsequence | LC 718: Maximum Length of Repeated Subarray
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 1143: Longest Common Subsequence
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = text1[i-1] == text2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[m][n];
}

// LC 718: Maximum Length of Repeated Subarray (contiguous)
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size(), maxLen = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (nums1[i-1] == nums2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen;
}

// LC 1312: Minimum Insertions to Make Palindrome
int minInsertions(string s) {
    int n = s.size();
    string reversed(s.rbegin(), s.rend());
    return n - longestCommonSubsequence(s, reversed);
}

int main() {
    cout << "LCS 'abcde','ace': " << longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
