// LC 23: Merge K Sorted Lists | Pattern: K-way Merge with Heap
// Time: O(N log k) | Space: O(k)
// Recognition: "Merge k sorted data structures"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto list : lists) if (list) pq.push(list);
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

int main() {
    cout << "Merge K Sorted Lists - uses min heap\n";
    return 0;
}
