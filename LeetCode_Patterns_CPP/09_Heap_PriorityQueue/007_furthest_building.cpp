// LC 1642: Furthest Building | LC 1046: Last Stone Weight
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 1642: Furthest Building (ladders = greedy, bricks = fill)
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<>> pq;  // Min heap of ladder climbs
    for (int i = 0; i < (int)heights.size() - 1; i++) {
        int diff = heights[i + 1] - heights[i];
        if (diff <= 0) continue;
        pq.push(diff);
        if ((int)pq.size() > ladders) {
            bricks -= pq.top(); pq.pop();
            if (bricks < 0) return i;
        }
    }
    return heights.size() - 1;
}

// LC 1046: Last Stone Weight
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if (a != b) pq.push(a - b);
    }
    return pq.empty() ? 0 : pq.top();
}

// LC 253: Meeting Rooms II (min meeting rooms)
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<>> pq;  // End times
    for (auto& iv : intervals) {
        if (!pq.empty() && pq.top() <= iv[0]) pq.pop();
        pq.push(iv[1]);
    }
    return pq.size();
}

int main() {
    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    cout << "Furthest building: " << furthestBuilding(heights, 5, 1) << endl;
    return 0;
}
