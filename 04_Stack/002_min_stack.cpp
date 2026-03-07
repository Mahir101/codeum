// LC 155: Min Stack
// Pattern: Stack with Min Tracking
// Time: O(1) all operations | Space: O(n)
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<pair<int, int>> stk;  // {value, min_so_far}
public:
    void push(int val) {
        int minVal = stk.empty() ? val : min(val, stk.top().second);
        stk.push({val, minVal});
    }
    
    void pop() { stk.pop(); }
    int top() { return stk.top().first; }
    int getMin() { return stk.top().second; }
};

int main() {
    MinStack s;
    s.push(-2); s.push(0); s.push(-3);
    cout << "Min: " << s.getMin() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    cout << "Min: " << s.getMin() << endl;
    return 0;
}
