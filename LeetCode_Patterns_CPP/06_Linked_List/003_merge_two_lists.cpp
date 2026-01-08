// LC 21: Merge Two Sorted Lists | Pattern: Two Pointer Merge
// Time: O(n+m) | Space: O(1)
#include <iostream>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0), *tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main() { cout << "Merge sorted lists - dummy head technique\n"; return 0; }
