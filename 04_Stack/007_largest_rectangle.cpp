// LC 84: Largest Rectangle in Histogram
// Pattern: Monotonic Stack (Increasing)
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!stk.empty() && h < heights[stk.top()]) {
            int height = heights[stk.top()];
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        stk.push(i);
    }
    
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle: " << largestRectangleArea(heights) << endl;
    return 0;
}
