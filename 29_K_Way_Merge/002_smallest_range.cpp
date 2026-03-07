// LC 632: Smallest Range Covering Elements from K Lists
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    // {value, list_idx, element_idx}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
    int maxVal = INT_MIN;
    
    for (int i = 0; i < k; i++) {
        minHeap.push({nums[i][0], i, 0});
        maxVal = max(maxVal, nums[i][0]);
    }
    
    int rangeStart = 0, rangeEnd = INT_MAX;
    
    while (true) {
        auto [minVal, listIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        
        if (maxVal - minVal < rangeEnd - rangeStart) {
            rangeStart = minVal;
            rangeEnd = maxVal;
        }
        
        if (elemIdx + 1 >= (int)nums[listIdx].size()) break;
        
        int nextVal = nums[listIdx][elemIdx + 1];
        minHeap.push({nextVal, listIdx, elemIdx + 1});
        maxVal = max(maxVal, nextVal);
    }
    
    return {rangeStart, rangeEnd};
}

int main() {
    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    auto range = smallestRange(nums);
    cout << "Smallest range: [" << range[0] << ", " << range[1] << "]\n";
    return 0;
}
