// K-way Merge Pattern
// LC 23: Merge K Sorted Lists | LC 378: Kth Smallest in Sorted Matrix
// LC 373: Find K Pairs with Smallest Sums | LC 632: Smallest Range
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 23: Merge K Sorted Lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
    for (auto list : lists) if (list) minHeap.push(list);
    ListNode dummy(0); ListNode* tail = &dummy;
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top(); minHeap.pop();
        tail->next = node; tail = tail->next;
        if (node->next) minHeap.push(node->next);
    }
    return dummy.next;
}

// LC 378: Kth Smallest Element in Sorted Matrix
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
    for (int i = 0; i < min(n, k); i++) minHeap.push({matrix[i][0], i, 0});
    int result = 0;
    while (k-- > 0) {
        auto [val, row, col] = minHeap.top(); minHeap.pop();
        result = val;
        if (col + 1 < n) minHeap.push({matrix[row][col+1], row, col+1});
    }
    return result;
}

// LC 373: K Pairs with Smallest Sums
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
    for (int i = 0; i < min((int)nums1.size(), k); i++) minHeap.push({nums1[i]+nums2[0], i, 0});
    vector<vector<int>> result;
    while (k-- > 0 && !minHeap.empty()) {
        auto [sum, i, j] = minHeap.top(); minHeap.pop();
        result.push_back({nums1[i], nums2[j]});
        if (j + 1 < (int)nums2.size()) minHeap.push({nums1[i]+nums2[j+1], i, j+1});
    }
    return result;
}

int main() { cout << "K-way Merge Pattern\n"; return 0; }
