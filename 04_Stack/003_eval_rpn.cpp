// LC 150: Evaluate Reverse Polish Notation
// Pattern: Stack for Expression Evaluation
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            if (token == "+") stk.push(a + b);
            else if (token == "-") stk.push(a - b);
            else if (token == "*") stk.push(a * b);
            else stk.push(a / b);
        } else {
            stk.push(stoi(token));
        }
    }
    return stk.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "RPN result: " << evalRPN(tokens) << endl;
    return 0;
}
