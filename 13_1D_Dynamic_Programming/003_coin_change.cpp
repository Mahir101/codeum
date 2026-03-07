// LC 322: Coin Change | Pattern: Unbounded Knapsack
// Time: O(n*amount) | Space: O(amount)
// Recognition: "Min coins to make amount, unlimited use"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Min coins for 11: " << coinChange(coins, 11) << endl;
    return 0;
}
