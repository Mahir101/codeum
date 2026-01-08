// Top K Elements Pattern
// LC 215: Kth Largest | LC 347: Top K Frequent | LC 973: K Closest Points
// LC 658: Find K Closest Elements | LC 767: Reorganize String
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// LC 215: Kth Largest Element (Min Heap)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// LC 973: K Closest Points to Origin
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto dist = [](vector<int>& p) { return p[0]*p[0] + p[1]*p[1]; };
    priority_queue<pair<int, int>> maxHeap;  // {dist, index}
    for (int i = 0; i < (int)points.size(); i++) {
        maxHeap.push({dist(points[i]), i});
        if ((int)maxHeap.size() > k) maxHeap.pop();
    }
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }
    return result;
}

// LC 451: Sort Characters By Frequency
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    priority_queue<pair<int, char>> maxHeap;
    for (auto& [c, f] : freq) maxHeap.push({f, c});
    string result;
    while (!maxHeap.empty()) {
        auto [f, c] = maxHeap.top(); maxHeap.pop();
        result += string(f, c);
    }
    return result;
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << "2nd largest: " << findKthLargest(nums, 2) << endl;
    return 0;
}
