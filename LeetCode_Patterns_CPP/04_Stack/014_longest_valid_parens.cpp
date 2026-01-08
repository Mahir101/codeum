// LC 32: Longest Valid Parentheses
// Pattern: Stack with Index Tracking
// Time: O(n) | Space: O(n)
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int maxLen = 0;
    
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxLen = max(maxLen, i - stk.top());
            }
        }
    }
    
    return maxLen;
}

// Alternative: Two pass O(1) space
int longestValidParentheses2(string s) {
    int left = 0, right = 0, maxLen = 0;
    
    for (char c : s) {
        if (c == '(') left++;
        else right++;
        if (left == right) maxLen = max(maxLen, 2 * right);
        else if (right > left) left = right = 0;
    }
    
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        else right++;
        if (left == right) maxLen = max(maxLen, 2 * left);
        else if (left > right) left = right = 0;
    }
    
    return maxLen;
}

int main() {
    cout << "\"(()\": " << longestValidParentheses("(()") << endl;
    cout << "\")()())\": " << longestValidParentheses(")()())") << endl;
    return 0;
}
