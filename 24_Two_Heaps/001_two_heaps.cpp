// Two Heaps Pattern - Maintain two heaps for median/balance
// LC 295: Find Median from Data Stream | LC 480: Sliding Window Median
// LC 502: IPO | LC 436: Find Right Interval
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// LC 295: Find Median from Data Stream
class MedianFinder {
    priority_queue<int> maxHeap;  // Lower half
    priority_queue<int, vector<int>, greater<>> minHeap;  // Upper half
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) { maxHeap.push(minHeap.top()); minHeap.pop(); }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

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
        w += maxProfit.top(); maxProfit.pop();
    }
    return w;
}

int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2); mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;
    return 0;
}
