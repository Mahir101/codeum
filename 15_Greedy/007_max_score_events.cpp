// LC 1537: Get Max Score | LC 1665: Minimum Initial Energy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 1537: Get Maximum Score (two sorted arrays)
int maxSum(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, m = nums1.size(), n = nums2.size();
    long sum1 = 0, sum2 = 0;
    int mod = 1e9 + 7;
    
    while (i < m || j < n) {
        if (i < m && (j >= n || nums1[i] < nums2[j])) sum1 += nums1[i++];
        else if (j < n && (i >= m || nums2[j] < nums1[i])) sum2 += nums2[j++];
        else {  // nums1[i] == nums2[j]
            sum1 = sum2 = max(sum1, sum2) + nums1[i];
            i++; j++;
        }
    }
    return max(sum1, sum2) % mod;
}

// LC 1665: Minimum Initial Energy
int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    });
    int energy = 0, curr = 0;
    for (auto& t : tasks) {
        if (curr < t[1]) { energy += t[1] - curr; curr = t[1]; }
        curr -= t[0];
    }
    return energy;
}

// LC 1353: Maximum Number of Events
int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<>> pq;
    int i = 0, n = events.size(), day = 0, count = 0;
    
    while (i < n || !pq.empty()) {
        if (pq.empty()) day = events[i][0];
        while (i < n && events[i][0] == day) pq.push(events[i++][1]);
        pq.pop(); count++; day++;
        while (!pq.empty() && pq.top() < day) pq.pop();
    }
    return count;
}

int main() { cout << "Two pointer greedy patterns\n"; return 0; }
