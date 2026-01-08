// LC 57: Insert Interval | LC 986: Interval List Intersections
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 57: Insert Interval
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    // Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0])
        result.push_back(intervals[i++]);
    // Merge overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    // Add remaining intervals
    while (i < n) result.push_back(intervals[i++]);
    return result;
}

// LC 986: Interval List Intersections
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> result;
    int i = 0, j = 0;
    while (i < (int)A.size() && j < (int)B.size()) {
        int lo = max(A[i][0], B[j][0]);
        int hi = min(A[i][1], B[j][1]);
        if (lo <= hi) result.push_back({lo, hi});
        if (A[i][1] < B[j][1]) i++;
        else j++;
    }
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    auto result = insert(intervals, {2, 5});
    cout << "After insert: " << result.size() << " intervals\n";
    return 0;
}
