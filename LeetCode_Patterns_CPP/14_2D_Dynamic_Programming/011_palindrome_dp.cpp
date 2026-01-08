// LC 516: Longest Palindromic Subsequence | LC 647: Palindromic Substrings
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC 516: Longest Palindromic Subsequence
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

// LC 647: Count Palindromic Substrings
int countSubstrings(string s) {
    int n = s.size(), count = 0;
    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) { count++; left--; right++; }
    };
    for (int i = 0; i < n; i++) { expand(i, i); expand(i, i + 1); }
    return count;
}

// LC 131: Palindrome Partitioning Count
int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            isPalin[i][j] = s[i] == s[j] && (j - i <= 2 || isPalin[i+1][j-1]);
    
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        if (isPalin[0][i]) dp[i] = 0;
        else {
            dp[i] = i;
            for (int j = 1; j <= i; j++)
                if (isPalin[j][i]) dp[i] = min(dp[i], dp[j-1] + 1);
        }
    }
    return dp[n-1];
}

int main() {
    cout << "LPS 'bbbab': " << longestPalindromeSubseq("bbbab") << endl;
    cout << "Count 'abc': " << countSubstrings("abc") << endl;
    return 0;
}
