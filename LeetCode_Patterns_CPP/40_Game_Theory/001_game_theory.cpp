// Game Theory Pattern (Minimax, Nim, Stone Games)
// LC 292: Nim Game | LC 877: Stone Game | LC 1140: Stone Game II
// LC 464: Can I Win | LC 486: Predict the Winner
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 292: Nim Game (just math)
bool canWinNim(int n) { return n % 4 != 0; }

// LC 877: Stone Game (always wins due to parity)
bool stoneGame(vector<int>& piles) { return true; }  // First player always has strategy to win

// LC 486: Predict the Winner (Minimax DP)
bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = nums[i];
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1] >= 0;
}

// LC 464: Can I Win (Bitmask DP)
unordered_map<int, bool> memo;
bool canIWinHelper(int maxInt, int desiredTotal, int used) {
    if (memo.count(used)) return memo[used];
    for (int i = 1; i <= maxInt; i++) {
        if (used & (1 << i)) continue;
        if (i >= desiredTotal || !canIWinHelper(maxInt, desiredTotal - i, used | (1 << i)))
            return memo[used] = true;
    }
    return memo[used] = false;
}

bool canIWin(int maxInt, int desiredTotal) {
    if (desiredTotal <= 0) return true;
    int sum = maxInt * (maxInt + 1) / 2;
    if (sum < desiredTotal) return false;
    memo.clear();
    return canIWinHelper(maxInt, desiredTotal, 0);
}

int main() {
    cout << "Nim(4): " << canWinNim(4) << " (should be 0)\n";
    vector<int> nums = {1, 5, 233, 7};
    cout << "Predict winner: " << predictTheWinner(nums) << endl;
    return 0;
}
