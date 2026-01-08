// LC 632: Smallest Range | LC 759: Employee Free Time (with Heap)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 632: Smallest Range Covering Elements from K Lists
vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    int maxVal = INT_MIN;
    for (int i = 0; i < (int)nums.size(); i++) {
        pq.push({nums[i][0], i, 0});
        maxVal = max(maxVal, nums[i][0]);
    }
    
    vector<int> result = {0, INT_MAX};
    while (true) {
        auto [minVal, row, col] = pq.top(); pq.pop();
        if (maxVal - minVal < result[1] - result[0]) result = {minVal, maxVal};
        if (col + 1 == (int)nums[row].size()) break;
        int next = nums[row][col + 1];
        maxVal = max(maxVal, next);
        pq.push({next, row, col + 1});
    }
    return result;
}

// LC 759: Employee Free Time (merge intervals variation)
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    // Min heap of {start, end, empIdx, intervalIdx}
    priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> pq;
    for (int i = 0; i < (int)schedule.size(); i++)
        if (!schedule[i].empty()) pq.push({schedule[i][0][0], schedule[i][0][1], i, 0});
    
    vector<vector<int>> result;
    int prevEnd = -1;
    while (!pq.empty()) {
        auto [start, end, emp, idx] = pq.top(); pq.pop();
        if (prevEnd != -1 && start > prevEnd) result.push_back({prevEnd, start});
        prevEnd = max(prevEnd, end);
        if (idx + 1 < (int)schedule[emp].size())
            pq.push({schedule[emp][idx+1][0], schedule[emp][idx+1][1], emp, idx + 1});
    }
    return result;
}

int main() {
    vector<vector<int>> lists = {{4,10,15,24},{0,9,12,20},{5,18,22,30}};
    auto range = smallestRange(lists);
    cout << "Smallest range: [" << range[0] << ", " << range[1] << "]\n";
    return 0;
}
