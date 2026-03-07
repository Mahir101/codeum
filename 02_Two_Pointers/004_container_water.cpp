// LC 11: Container With Most Water
// Pattern: Two Pointers (Greedy Shrink)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        maxWater = max(maxWater, width * h);
        
        // Move the shorter line
        if (height[left] < height[right]) left++;
        else right--;
    }
    
    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water: " << maxArea(height) << endl;
    return 0;
}
