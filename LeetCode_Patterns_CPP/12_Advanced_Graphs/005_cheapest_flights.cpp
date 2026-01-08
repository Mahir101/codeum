// LC 787: Cheapest Flights Within K Stops | Pattern: Bellman-Ford / BFS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Bellman-Ford variation (K+1 iterations)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prices(n, INT_MAX);
    prices[src] = 0;
    
    for (int i = 0; i <= k; i++) {
        vector<int> temp = prices;
        for (auto& f : flights) {
            int from = f[0], to = f[1], price = f[2];
            if (prices[from] != INT_MAX)
                temp[to] = min(temp[to], prices[from] + price);
        }
        prices = temp;
    }
    return prices[dst] == INT_MAX ? -1 : prices[dst];
}

int main() {
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {0,2,500}};
    cout << "Cheapest 0->2 with 1 stop: " << findCheapestPrice(3, flights, 0, 2, 1) << endl;
    return 0;
}
