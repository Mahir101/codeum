// LC 227: Basic Calculator II | LC 224: Basic Calculator
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// LC 227: Basic Calculator II (+ - * /)
int calculate(string s) {
    stack<int> stk;
    int num = 0;
    char op = '+';
    for (int i = 0; i <= (int)s.size(); i++) {
        char c = i < (int)s.size() ? s[i] : '+';
        if (isdigit(c)) num = num * 10 + (c - '0');
        else if (c != ' ') {
            if (op == '+') stk.push(num);
            else if (op == '-') stk.push(-num);
            else if (op == '*') { int top = stk.top(); stk.pop(); stk.push(top * num); }
            else if (op == '/') { int top = stk.top(); stk.pop(); stk.push(top / num); }
            op = c; num = 0;
        }
    }
    int result = 0;
    while (!stk.empty()) { result += stk.top(); stk.pop(); }
    return result;
}

// LC 224: Basic Calculator (with parentheses, + -)
int calculateWithParens(string s) {
    stack<int> nums, signs;
    int result = 0, num = 0, sign = 1;
    for (char c : s) {
        if (isdigit(c)) num = num * 10 + (c - '0');
        else if (c == '+' || c == '-') {
            result += sign * num; num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            nums.push(result); signs.push(sign);
            result = 0; sign = 1;
        } else if (c == ')') {
            result += sign * num; num = 0;
            result = nums.top() + signs.top() * result;
            nums.pop(); signs.pop();
        }
    }
    return result + sign * num;
}

int main() {
    cout << "3+2*2 = " << calculate("3+2*2") << endl;
    cout << "(1+(4+5+2)-3) = " << calculateWithParens("(1+(4+5+2)-3)") << endl;
    return 0;
}
