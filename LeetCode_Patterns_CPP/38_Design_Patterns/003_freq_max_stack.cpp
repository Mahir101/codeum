// LC 895: Maximum Frequency Stack | LC 716: Max Stack
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// LC 895: FreqStack
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq = 0;
public:
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        group[freq[val]].push(val);
    }
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }
};

// LC 716: MaxStack (using two stacks)
class MaxStack {
    stack<int> stk, maxStk;
public:
    void push(int x) {
        stk.push(x);
        maxStk.push(maxStk.empty() ? x : max(x, maxStk.top()));
    }
    int pop() { int x = stk.top(); stk.pop(); maxStk.pop(); return x; }
    int top() { return stk.top(); }
    int peekMax() { return maxStk.top(); }
    int popMax() {
        int maxVal = maxStk.top();
        stack<int> temp;
        while (stk.top() != maxVal) { temp.push(pop()); }
        pop();
        while (!temp.empty()) { push(temp.top()); temp.pop(); }
        return maxVal;
    }
};

int main() {
    FreqStack fs;
    fs.push(5); fs.push(7); fs.push(5); fs.push(7); fs.push(4); fs.push(5);
    cout << "FreqStack pop: " << fs.pop() << endl;  // 5
    return 0;
}
