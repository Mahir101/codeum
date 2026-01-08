// LC 139: Word Break | Pattern: String Partition DP
// Time: O(n^2) | Space: O(n)
// Recognition: "Can string be segmented into dictionary words"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    vector<string> dict = {"leet", "code"};
    cout << "Can break 'leetcode': " << wordBreak("leetcode", dict) << endl;
    return 0;
}
