// LC 739: Daily Temperatures
// Pattern: Monotonic Stack (Decreasing)
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> stk;  // Indices of unresolved temperatures
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            int prevIdx = stk.top();
            stk.pop();
            result[prevIdx] = i - prevIdx;
        }
        stk.push(i);
    }
    
    return result;
}

int main() {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    auto result = dailyTemperatures(temps);
    cout << "Days to wait: ";
    for (int d : result) cout << d << " ";
    cout << endl;
    return 0;
}
