// LC 188: Best Time to Buy and Sell Stock IV | Pattern: State Machine DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 188: At Most K Transactions
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    if (k >= n / 2) {  // Unlimited transactions
        int profit = 0;
        for (int i = 1; i < n; i++) profit += max(0, prices[i] - prices[i-1]);
        return profit;
    }
    
    vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
    for (int price : prices) {
        for (int j = 1; j <= k; j++) {
            buy[j] = max(buy[j], sell[j-1] - price);
            sell[j] = max(sell[j], buy[j] + price);
        }
    }
    return sell[k];
}

// LC 714: With Transaction Fee
int maxProfitWithFee(vector<int>& prices, int fee) {
    int n = prices.size();
    int hold = -prices[0], cash = 0;
    for (int i = 1; i < n; i++) {
        hold = max(hold, cash - prices[i]);
        cash = max(cash, hold + prices[i] - fee);
    }
    return cash;
}

// LC 123: At Most 2 Transactions
int maxProfitTwo(vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (int price : prices) {
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price);
        buy2 = max(buy2, sell1 - price);
        sell2 = max(sell2, buy2 + price);
    }
    return sell2;
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    cout << "Max profit (k=2): " << maxProfit(2, prices) << endl;
    return 0;
}
