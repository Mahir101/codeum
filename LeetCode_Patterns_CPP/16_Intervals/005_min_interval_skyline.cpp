// LC 1851: Minimum Interval to Include Each Query
// LC 218: The Skyline Problem
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// LC 1851: Minimum Interval (offline queries + sort + heap)
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> sortedQ;
    for (int i = 0; i < (int)queries.size(); i++) sortedQ.push_back({queries[i], i});
    sort(sortedQ.begin(), sortedQ.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // {size, right}
    vector<int> result(queries.size(), -1);
    int j = 0;
    
    for (auto& [q, idx] : sortedQ) {
        while (j < (int)intervals.size() && intervals[j][0] <= q)
            pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j++][1]});
        while (!pq.empty() && pq.top().second < q) pq.pop();
        if (!pq.empty()) result[idx] = pq.top().first;
    }
    return result;
}

// LC 218: Skyline Problem
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    for (auto& b : buildings) {
        events.push_back({b[0], -b[2]});  // Start: negative height
        events.push_back({b[1], b[2]});   // End: positive height
    }
    sort(events.begin(), events.end());
    
    vector<vector<int>> result;
    multiset<int> heights = {0};
    int prevMax = 0;
    
    for (auto& [x, h] : events) {
        if (h < 0) heights.insert(-h);
        else heights.erase(heights.find(h));
        int currMax = *heights.rbegin();
        if (currMax != prevMax) {
            result.push_back({x, currMax});
            prevMax = currMax;
        }
    }
    return result;
}

int main() { cout << "Interval and Skyline problems\n"; return 0; }
