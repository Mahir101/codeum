// LC 256: Paint House | LC 265: Paint House II
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// LC 256: Paint House (3 colors)
int minCost(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = costs.size();
    vector<int> dp = costs[0];
    for (int i = 1; i < n; i++) {
        vector<int> newDp(3);
        newDp[0] = costs[i][0] + min(dp[1], dp[2]);
        newDp[1] = costs[i][1] + min(dp[0], dp[2]);
        newDp[2] = costs[i][2] + min(dp[0], dp[1]);
        dp = newDp;
    }
    return *min_element(dp.begin(), dp.end());
}

// LC 265: Paint House II (k colors) - O(nk) optimized
int minCostII(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = costs.size(), k = costs[0].size();
    int min1 = 0, min2 = 0, idx1 = -1;
    
    for (int i = 0; i < n; i++) {
        int newMin1 = INT_MAX, newMin2 = INT_MAX, newIdx1 = -1;
        for (int j = 0; j < k; j++) {
            int cost = costs[i][j] + (j == idx1 ? min2 : min1);
            if (cost < newMin1) { newMin2 = newMin1; newMin1 = cost; newIdx1 = j; }
            else if (cost < newMin2) newMin2 = cost;
        }
        min1 = newMin1; min2 = newMin2; idx1 = newIdx1;
    }
    return min1;
}

int main() {
    vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}};
    cout << "Min cost: " << minCost(costs) << endl;
    return 0;
}
