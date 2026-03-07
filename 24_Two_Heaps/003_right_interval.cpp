// LC 436: Find Right Interval | Two Heaps for Scheduling
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// LC 436: Find Right Interval (binary search approach)
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    map<int, int> startToIdx;
    for (int i = 0; i < (int)intervals.size(); i++)
        startToIdx[intervals[i][0]] = i;
    
    vector<int> result;
    for (auto& iv : intervals) {
        auto it = startToIdx.lower_bound(iv[1]);
        result.push_back(it == startToIdx.end() ? -1 : it->second);
    }
    return result;
}

// Scheduling with Two Heaps
class TaskScheduler {
    priority_queue<pair<int, int>> maxStart;  // {-start, idx}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minEnd;  // {end, idx}
    
public:
    void addTask(int start, int end, int idx) {
        maxStart.push({-start, idx});
        minEnd.push({end, idx});
    }
    
    // Find tasks that can start after given time
    vector<int> getAvailableTasks(int time) {
        vector<int> tasks;
        while (!minEnd.empty() && minEnd.top().first <= time) {
            tasks.push_back(minEnd.top().second);
            minEnd.pop();
        }
        return tasks;
    }
};

int main() {
    vector<vector<int>> intervals = {{3,4},{2,3},{1,2}};
    auto result = findRightInterval(intervals);
    cout << "Right intervals: ";
    for (int r : result) cout << r << " ";
    cout << endl;
    return 0;
}
