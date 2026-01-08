// LC 692: Top K Frequent Words | LC 703: Kth Largest in Stream
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// LC 692: Top K Frequent Words
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    for (auto& w : words) freq[w]++;
    
    auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
    
    for (auto& [word, f] : freq) {
        pq.push({f, word});
        if ((int)pq.size() > k) pq.pop();
    }
    
    vector<string> result(k);
    for (int i = k - 1; i >= 0; i--) { result[i] = pq.top().second; pq.pop(); }
    return result;
}

// LC 703: Kth Largest Element in a Stream
class KthLargest {
    priority_queue<int, vector<int>, greater<>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int n : nums) add(n);
    }
    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

int main() {
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    auto result = topKFrequent(words, 2);
    cout << "Top 2: "; for (auto& w : result) cout << w << " "; cout << endl;
    return 0;
}
