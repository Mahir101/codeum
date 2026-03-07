// LC 1235: Maximum Profit in Job Scheduling | Pattern: DP + Binary Search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<tuple<int, int, int>> jobs(n);
    for (int i = 0; i < n; i++) jobs[i] = {endTime[i], startTime[i], profit[i]};
    sort(jobs.begin(), jobs.end());
    
    vector<pair<int, int>> dp;  // {endTime, maxProfit}
    dp.push_back({0, 0});
    
    for (auto& [end, start, p] : jobs) {
        // Binary search for last job ending before start
        auto it = upper_bound(dp.begin(), dp.end(), make_pair(start, INT_MAX));
        --it;
        int newProfit = it->second + p;
        if (newProfit > dp.back().second) {
            dp.push_back({end, newProfit});
        }
    }
    return dp.back().second;
}

int main() {
    vector<int> start = {1, 2, 3, 3}, end = {3, 4, 5, 6}, profit = {50, 10, 40, 70};
    cout << "Max profit: " << jobScheduling(start, end, profit) << endl;
    return 0;
}
