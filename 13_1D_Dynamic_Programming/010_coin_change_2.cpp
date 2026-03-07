// LC 518: Coin Change 2 (count ways) | LC 279: Perfect Squares
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// LC 518: Coin Change 2 (count combinations)
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

// LC 279: Perfect Squares
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Ways to make 5: " << change(5, coins) << endl;
    cout << "Perfect squares for 12: " << numSquares(12) << endl;
    return 0;
}
