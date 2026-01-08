// LC 87: Scramble String | LC 241: Different Ways to Add Parentheses (Recursion Memoization)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 241: Different Ways to Add Parentheses
unordered_map<string, vector<int>> memo;

vector<int> diffWaysToCompute(string expression) {
    if (memo.count(expression)) return memo[expression];
    vector<int> result;
    
    for (int i = 0; i < (int)expression.size(); i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i + 1));
            for (int l : left) {
                for (int r : right) {
                    if (c == '+') result.push_back(l + r);
                    else if (c == '-') result.push_back(l - r);
                    else result.push_back(l * r);
                }
            }
        }
    }
    
    if (result.empty()) result.push_back(stoi(expression));
    return memo[expression] = result;
}

// Catalan Number - Count BSTs and Balanced Parens
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - 1 - j];
    return dp[n];
}

int main() {
    auto ways = diffWaysToCompute("2*3-4*5");
    cout << "Ways: " << ways.size() << endl;
    cout << "BSTs with 3 nodes: " << numTrees(3) << endl;
    return 0;
}
