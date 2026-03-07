// LC 309: Best Time Buy Sell with Cooldown | LC 188: Buy Sell K Transactions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 309: With Cooldown
int maxProfitCooldown(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    int hold = -prices[0], sold = 0, rest = 0;
    for (int i = 1; i < n; i++) {
        int prevSold = sold;
        sold = hold + prices[i];
        hold = max(hold, rest - prices[i]);
        rest = max(rest, prevSold);
    }
    return max(sold, rest);
}

// LC 122: Unlimited transactions
int maxProfitUnlimited(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); i++)
        if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
    return profit;
}

// LC 121: One transaction
int maxProfitOnce(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max profit with cooldown: " << maxProfitCooldown(prices) << endl;
    return 0;
}
