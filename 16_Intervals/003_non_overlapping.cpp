// LC 435: Non-overlapping Intervals | LC 452: Minimum Arrows
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 435: Minimum intervals to remove for non-overlapping
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[1] < b[1];  // Sort by end time
    });
    int count = 0, end = intervals[0][1];
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] < end) count++;  // Overlap, remove this
        else end = intervals[i][1];
    }
    return count;
}

// LC 452: Minimum arrows to burst all balloons
int findMinArrowPoints(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    int arrows = 1, end = points[0][1];
    for (int i = 1; i < (int)points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Remove to non-overlap: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}
