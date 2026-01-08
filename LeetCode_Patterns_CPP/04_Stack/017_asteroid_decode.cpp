// LC 735: Asteroid Collision | LC 394: Decode String
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// LC 735: Asteroid Collision
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> stk;
    for (int ast : asteroids) {
        bool destroyed = false;
        while (!stk.empty() && ast < 0 && stk.top() > 0) {
            if (stk.top() < -ast) { stk.pop(); continue; }
            else if (stk.top() == -ast) stk.pop();
            destroyed = true; break;
        }
        if (!destroyed) stk.push(ast);
    }
    vector<int> result(stk.size());
    for (int i = stk.size() - 1; i >= 0; i--) { result[i] = stk.top(); stk.pop(); }
    return result;
}

// LC 394: Decode String
string decodeString(string s) {
    stack<string> strStk;
    stack<int> numStk;
    string curr = "";
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) num = num * 10 + (c - '0');
        else if (c == '[') {
            strStk.push(curr); numStk.push(num);
            curr = ""; num = 0;
        } else if (c == ']') {
            string temp = curr;
            curr = strStk.top(); strStk.pop();
            int repeat = numStk.top(); numStk.pop();
            while (repeat--) curr += temp;
        } else curr += c;
    }
    return curr;
}

int main() {
    string s = "3[a2[c]]";
    cout << "Decode '" << s << "': " << decodeString(s) << endl;
    return 0;
}
