// LC 1617: Count Subtrees With Max Distance Between Cities
// LC 943: Find the Shortest Superstring (Bitmask DP)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LC 943: Shortest Superstring (TSP-like Bitmask DP)
string shortestSuperstring(vector<string>& words) {
    int n = words.size();
    // overlap[i][j] = length of overlap when words[i] followed by words[j]
    vector<vector<int>> overlap(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int maxLen = min(words[i].size(), words[j].size());
                for (int k = maxLen; k >= 0; k--) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
    }
    
    // dp[mask][i] = max overlap for subset mask ending at word i
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));
    
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;
            int prevMask = mask ^ (1 << last);
            if (prevMask == 0) continue;
            for (int prev = 0; prev < n; prev++) {
                if (!(prevMask & (1 << prev))) continue;
                int val = dp[prevMask][prev] + overlap[prev][last];
                if (val > dp[mask][last]) {
                    dp[mask][last] = val;
                    parent[mask][last] = prev;
                }
            }
        }
    }
    
    // Reconstruct
    int mask = (1 << n) - 1;
    int last = max_element(dp[mask].begin(), dp[mask].end()) - dp[mask].begin();
    vector<int> order;
    while (mask) { order.push_back(last); int prev = parent[mask][last]; mask ^= (1 << last); last = prev; }
    reverse(order.begin(), order.end());
    
    string result = words[order[0]];
    for (int i = 1; i < n; i++)
        result += words[order[i]].substr(overlap[order[i-1]][order[i]]);
    return result;
}

int main() {
    vector<string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    cout << "Shortest superstring: " << shortestSuperstring(words) << endl;
    return 0;
}
