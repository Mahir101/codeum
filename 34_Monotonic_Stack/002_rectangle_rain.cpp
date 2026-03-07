// LC 85: Maximal Rectangle | LC 42: Trapping Rain Water (stack)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// LC 85: Maximal Rectangle (using LC 84 as subroutine)
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

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

// LC 42: Trapping Rain Water (monotonic stack)
int trap(vector<int>& height) {
    stack<int> stk;
    int water = 0;
    for (int i = 0; i < (int)height.size(); i++) {
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int bottom = stk.top(); stk.pop();
            if (stk.empty()) break;
            int w = i - stk.top() - 1;
            int h = min(height[i], height[stk.top()]) - height[bottom];
            water += w * h;
        }
        stk.push(i);
    }
    return water;
}

int main() {
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water: " << trap(h) << endl;
    return 0;
}
