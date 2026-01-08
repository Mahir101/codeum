// LC 639: Decode Ways II | LC 1531: String Compression II
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC 639: Decode Ways II (with *)
int numDecodings(string s) {
    int n = s.size(), mod = 1e9 + 7;
    vector<long> dp(n + 1, 0);
    dp[0] = 1;
    
    auto decode1 = [](char c) -> long {
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    };
    
    auto decode2 = [](char c1, char c2) -> long {
        if (c1 == '*' && c2 == '*') return 15;  // 11-19, 21-26
        if (c1 == '*') return (c2 <= '6') ? 2 : 1;
        if (c2 == '*') {
            if (c1 == '1') return 9;
            if (c1 == '2') return 6;
            return 0;
        }
        int val = (c1 - '0') * 10 + (c2 - '0');
        return (val >= 10 && val <= 26) ? 1 : 0;
    };
    
    dp[1] = decode1(s[0]);
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] * decode1(s[i-1]) + dp[i-2] * decode2(s[i-2], s[i-1])) % mod;
    }
    return dp[n];
}

// LC 1531: String Compression II
int getLengthOfOptimalCompression(string s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));
    dp[0][0] = 0;
    
    auto getLen = [](int cnt) { return cnt <= 1 ? cnt : cnt <= 9 ? 2 : cnt <= 99 ? 3 : 4; };
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k && j < i; j++) {
            if (j < k) dp[i][j + 1] = min(dp[i][j + 1], dp[i-1][j]);  // Delete
            int same = 0, diff = 0;
            for (int l = i; l >= 1; l--) {
                if (s[l-1] == s[i-1]) same++;
                else if (++diff > j) break;
                dp[i][j] = min(dp[i][j], dp[l-1][j - diff] + getLen(same));
            }
        }
    }
    return dp[n][k];
}

int main() {
    cout << "Decode '*1*1*0': " << numDecodings("*1*1*0") << endl;
    return 0;
}
