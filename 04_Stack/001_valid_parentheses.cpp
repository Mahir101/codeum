// LC 20: Valid Parentheses
// Pattern: Stack for Matching
// Time: O(n) | Space: O(n)
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c : s) {
        if (pairs.count(c)) {
            if (stk.empty() || stk.top() != pairs[c]) return false;
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.empty();
}

int main() {
    cout << "\"()[]{}\": " << (isValid("()[]{}") ? "Valid" : "Invalid") << endl;
    cout << "\"([)]\": " << (isValid("([)]") ? "Valid" : "Invalid") << endl;
    return 0;
}
