// LC 56: Merge Intervals | Pattern: Sort + Sweep
// Time: O(n log n) | Space: O(n)
// Recognition: "Merge overlapping intervals"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result = {intervals[0]};
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    auto merged = merge(intervals);
    cout << "Merged intervals: " << merged.size() << " intervals\n";
    return 0;
}
