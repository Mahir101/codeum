// LC 132: Palindrome Partitioning II | LC 87: Scramble String
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 132: Minimum Cuts for Palindrome Partitioning
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

// LC 87: Scramble String
unordered_map<string, bool> memo;
bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    if (s1.size() != s2.size()) return false;
    string key = s1 + "#" + s2;
    if (memo.count(key)) return memo[key];
    
    int n = s1.size();
    string sorted1 = s1, sorted2 = s2;
    sort(sorted1.begin(), sorted1.end());
    sort(sorted2.begin(), sorted2.end());
    if (sorted1 != sorted2) return memo[key] = false;
    
    for (int i = 1; i < n; i++) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
            isScramble(s1.substr(i), s2.substr(i))) return memo[key] = true;
        if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
            isScramble(s1.substr(i), s2.substr(0, n - i))) return memo[key] = true;
    }
    return memo[key] = false;
}

int main() {
    cout << "Min cuts 'aab': " << minCut("aab") << endl;
    cout << "Scramble 'great','rgeat': " << isScramble("great", "rgeat") << endl;
    return 0;
}
