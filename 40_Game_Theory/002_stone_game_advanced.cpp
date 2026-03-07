// LC 1140: Stone Game II | LC 1406: Stone Game III
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// LC 1140: Stone Game II
int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<int> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
    
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int m = 1; m <= n; m++) {
            for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                int take = suffix[i] - suffix[i + x];
                int opponent = (i + x < n) ? dp[i + x][min(n, max(m, x))] : 0;
                dp[i][m] = max(dp[i][m], take + (suffix[i + x] - opponent));
            }
        }
    }
    return dp[0][1];
}

// LC 1406: Stone Game III (Alice, Bob, Charlie)
string stoneGameIII(vector<int>& stones) {
    int n = stones.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = INT_MIN;
        int take = 0;
        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stones[i + k];
            dp[i] = max(dp[i], take - dp[i + k + 1]);
        }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
}

int main() {
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << "Stone Game II: " << stoneGameII(piles) << endl;
    return 0;
}
