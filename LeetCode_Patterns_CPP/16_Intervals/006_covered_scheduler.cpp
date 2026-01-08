// LC 1288: Remove Covered Intervals | LC 1229: Meeting Scheduler
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 1288: Remove Covered Intervals
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
    int count = 0, maxEnd = 0;
    for (auto& iv : intervals) {
        if (iv[1] > maxEnd) { count++; maxEnd = iv[1]; }
    }
    return count;
}

// LC 1229: Meeting Scheduler (find free slot of duration)
vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());
    int i = 0, j = 0;
    while (i < (int)slots1.size() && j < (int)slots2.size()) {
        int start = max(slots1[i][0], slots2[j][0]);
        int end = min(slots1[i][1], slots2[j][1]);
        if (end - start >= duration) return {start, start + duration};
        if (slots1[i][1] < slots2[j][1]) i++;
        else j++;
    }
    return {};
}

// LC 759: Employee Free Time
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    vector<pair<int, int>> intervals;
    for (auto& emp : schedule)
        for (auto& iv : emp) intervals.push_back({iv[0], iv[1]});
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    int end = intervals[0].second;
    for (auto& [s, e] : intervals) {
        if (s > end) result.push_back({end, s});
        end = max(end, e);
    }
    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,4},{3,6},{2,8}};
    cout << "After removing covered: " << removeCoveredIntervals(intervals) << endl;
    return 0;
}
