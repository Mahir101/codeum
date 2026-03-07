// LC 294: Flip Game II | LC 375: Guess Number Higher or Lower II
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// LC 294: Flip Game II (Minimax)
unordered_map<string, bool> memo294;
bool canWin(string s) {
    if (memo294.count(s)) return memo294[s];
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] == '+' && s[i+1] == '+') {
            s[i] = s[i+1] = '-';
            bool opponentWins = canWin(s);
            s[i] = s[i+1] = '+';
            if (!opponentWins) return memo294[s] = true;
        }
    }
    return memo294[s] = false;
}

// LC 375: Guess Number Higher or Lower II
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                int cost = k + max(dp[i][k-1], dp[k+1][j]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}

// Sprague-Grundy theorem for Nim variants
int grundy(int n, vector<int>& memo) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    unordered_set<int> reachable;
    // Add all possible next states' Grundy numbers
    // For standard Nim: XOR of pile Grundy values
    return memo[n] = 0; // Placeholder
}

int main() {
    cout << "Guess n=10: " << getMoneyAmount(10) << endl;
    return 0;
}
