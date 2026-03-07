// LC 901: Online Stock Span
// Pattern: Monotonic Stack with Count
// Time: O(1) amortized | Space: O(n)
#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> stk;  // {price, span}
public:
    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    cout << "Stock spans: ";
    for (int p : prices) {
        cout << spanner.next(p) << " ";
    }
    cout << endl;
    return 0;
}
