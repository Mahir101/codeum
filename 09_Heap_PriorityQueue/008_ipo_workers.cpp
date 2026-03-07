// LC 502: IPO | LC 857: Minimum Cost to Hire K Workers
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// LC 502: IPO (maximize capital with k projects)
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) projects[i] = {capital[i], profits[i]};
    sort(projects.begin(), projects.end());
    
    priority_queue<int> maxProfit;
    int i = 0;
    while (k--) {
        while (i < n && projects[i].first <= w) {
            maxProfit.push(projects[i].second);
            i++;
        }
        if (maxProfit.empty()) break;
        w += maxProfit.top();
        maxProfit.pop();
    }
    return w;
}

// LC 857: Minimum Cost to Hire K Workers
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> workers(n);
    for (int i = 0; i < n; i++) workers[i] = {(double)wage[i] / quality[i], quality[i]};
    sort(workers.begin(), workers.end());
    
    priority_queue<int> maxHeap;
    int qualitySum = 0;
    double minCost = 1e18;
    
    for (auto& [ratio, q] : workers) {
        maxHeap.push(q);
        qualitySum += q;
        if ((int)maxHeap.size() > k) {
            qualitySum -= maxHeap.top();
            maxHeap.pop();
        }
        if ((int)maxHeap.size() == k) minCost = min(minCost, ratio * qualitySum);
    }
    return minCost;
}

int main() {
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};
    cout << "Max capital (k=2, w=0): " << findMaximizedCapital(2, 0, profits, capital) << endl;
    return 0;
}
