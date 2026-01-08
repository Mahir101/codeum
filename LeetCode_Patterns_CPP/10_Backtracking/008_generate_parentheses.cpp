// LC 22: Generate Parentheses | LC 301: Remove Invalid Parentheses
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// LC 22: Generate Valid Parentheses
vector<string> generateParenthesis(int n) {
    vector<string> result;
    function<void(string, int, int)> backtrack = [&](string curr, int open, int close) {
        if ((int)curr.size() == 2 * n) { result.push_back(curr); return; }
        if (open < n) backtrack(curr + "(", open + 1, close);
        if (close < open) backtrack(curr + ")", open, close + 1);
    };
    backtrack("", 0, 0);
    return result;
}

// LC 301: Remove Invalid Parentheses (minimum removals)
vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> result;
    int minRemove = INT_MAX;
    function<void(int, int, int, int, string)> dfs = [&](int i, int open, int close, int removed, string curr) {
        if (i == (int)s.size()) {
            if (open == close && removed <= minRemove) {
                if (removed < minRemove) { result.clear(); minRemove = removed; }
                result.insert(curr);
            }
            return;
        }
        if (s[i] != '(' && s[i] != ')') {
            dfs(i + 1, open, close, removed, curr + s[i]);
        } else {
            dfs(i + 1, open, close, removed + 1, curr);  // Remove
            if (s[i] == '(') dfs(i + 1, open + 1, close, removed, curr + "(");
            else if (close < open) dfs(i + 1, open, close + 1, removed, curr + ")");
        }
    };
    dfs(0, 0, 0, 0, "");
    return vector<string>(result.begin(), result.end());
}

int main() {
    auto parens = generateParenthesis(3);
    cout << "Generate(3): " << parens.size() << " combinations\n";
    return 0;
}
