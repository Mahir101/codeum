// LC 295: Find Median from Data Stream | Pattern: Two Heaps
#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;  // Lower half
    priority_queue<int, vector<int>, greater<>> minHeap;  // Upper half
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2); mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;
    return 0;
}
