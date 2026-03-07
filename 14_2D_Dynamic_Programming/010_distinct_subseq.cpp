// LC 115: Distinct Subsequences | LC 583: Delete Operation for Two Strings
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC 115: Distinct Subsequences
int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            if (s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[m][n];
}

// LC 583: Delete Operation for Two Strings (both can delete)
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    cout << "Distinct subseq 'rabbbit' in 'rabbit': " << numDistinct("rabbbit", "rabbit") << endl;
    cout << "Min delete 'sea' to 'eat': " << minDistance("sea", "eat") << endl;
    return 0;
}
