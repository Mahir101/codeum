// Monotonic Stack Pattern
// LC 739: Daily Temperatures | LC 496/503: Next Greater Element
// LC 84: Largest Rectangle | LC 42: Trapping Rain Water
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// LC 739: Daily Temperatures (next higher)
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> result(n, 0);
    stack<int> stk;  // Decreasing stack of indices
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && T[i] > T[stk.top()]) {
            result[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    return result;
}

// LC 84: Largest Rectangle in Histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int maxArea = 0, n = heights.size();
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!stk.empty() && h < heights[stk.top()]) {
            int height = heights[stk.top()]; stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        stk.push(i);
    }
    return maxArea;
}

// LC 907: Sum of Subarray Minimums
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size(), mod = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
        left[i] = stk.empty() ? i + 1 : i - stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
        right[i] = stk.empty() ? n - i : stk.top() - i;
        stk.push(i);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) sum = (sum + (long long)arr[i] * left[i] * right[i]) % mod;
    return sum;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle: " << largestRectangleArea(heights) << endl;
    return 0;
}
