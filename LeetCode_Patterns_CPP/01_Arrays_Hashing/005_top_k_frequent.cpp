// LC 347: Top K Frequent Elements
// Pattern: Bucket Sort / Heap
// Time: O(n) bucket | O(n log k) heap | Space: O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Approach 1: Bucket Sort - O(n)
vector<int> topKFrequentBucket(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;
    
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto& [num, count] : freq) {
        buckets[count].push_back(num);
    }
    
    vector<int> result;
    for (int i = buckets.size() - 1; i >= 0 && (int)result.size() < k; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if ((int)result.size() == k) break;
        }
    }
    return result;
}

// Approach 2: Min Heap - O(n log k)
vector<int> topKFrequentHeap(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto result = topKFrequentBucket(nums, 2);
    cout << "Top 2 frequent: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
