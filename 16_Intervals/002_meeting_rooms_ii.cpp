// LC 253: Meeting Rooms II | Pattern: Min Heap for Endpoints
// Time: O(n log n) | Space: O(n)
// Recognition: "Minimum resources for overlapping events"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<>> endTimes;
    for (auto& i : intervals) {
        if (!endTimes.empty() && endTimes.top() <= i[0]) {
            endTimes.pop();
        }
        endTimes.push(i[1]);
    }
    return endTimes.size();
}

int main() {
    vector<vector<int>> meetings = {{0,30}, {5,10}, {15,20}};
    cout << "Min rooms: " << minMeetingRooms(meetings) << endl;
    return 0;
}
