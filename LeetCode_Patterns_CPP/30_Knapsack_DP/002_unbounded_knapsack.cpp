// Unbounded Knapsack: Coin Change, Rod Cutting, Ribbon Cutting
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// LC 322: Coin Change (min coins)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int coin : coins)
            if (coin <= i) dp[i] = min(dp[i], dp[i - coin] + 1);
    return dp[amount] > amount ? -1 : dp[amount];
}

// LC 518: Coin Change 2 (count ways)
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
        for (int i = coin; i <= amount; i++)
            dp[i] += dp[i - coin];
    return dp[amount];
}

// Rod Cutting (maximize value)
int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
    return dp[n];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Min coins for 11: " << coinChange(coins, 11) << endl;
    cout << "Ways to make 5: " << change(5, coins) << endl;
    return 0;
}
