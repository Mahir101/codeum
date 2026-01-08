// LC 62: Unique Paths | Pattern: 2D Grid DP
// Time: O(m*n) | Space: O(n) optimized
// Recognition: "Count paths from top-left to bottom-right"
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main() {
    cout << "Unique paths 3x7: " << uniquePaths(3, 7) << endl;
    return 0;
}
