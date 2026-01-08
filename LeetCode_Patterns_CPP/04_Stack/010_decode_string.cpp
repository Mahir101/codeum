// LC 394: Decode String
// Pattern: Stack for Nested Structures
// Time: O(n) | Space: O(n)
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string current;
    int num = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            strStack.push(current);
            numStack.push(num);
            current = "";
            num = 0;
        } else if (c == ']') {
            string temp = current;
            current = strStack.top(); strStack.pop();
            int repeat = numStack.top(); numStack.pop();
            for (int i = 0; i < repeat; i++) current += temp;
        } else {
            current += c;
        }
    }
    
    return current;
}

int main() {
    cout << "3[a]2[bc]: " << decodeString("3[a]2[bc]") << endl;
    cout << "3[a2[c]]: " << decodeString("3[a2[c]]") << endl;
    return 0;
}
