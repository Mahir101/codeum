// LC 91: Decode Ways | LC 377: Combination Sum IV
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 91: Decode Ways
int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i-1] != '0') dp[i] = dp[i-1];
        int twoDigit = stoi(s.substr(i-2, 2));
        if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i-2];
    }
    return dp[n];
}

// LC 377: Combination Sum IV (order matters)
int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int num : nums) {
            if (num <= i) dp[i] += dp[i - num];
        }
    }
    return dp[target];
}

int main() {
    cout << "Decode '226': " << numDecodings("226") << endl;
    vector<int> nums = {1, 2, 3};
    cout << "Combination Sum IV target=4: " << combinationSum4(nums, 4) << endl;
    return 0;
}
