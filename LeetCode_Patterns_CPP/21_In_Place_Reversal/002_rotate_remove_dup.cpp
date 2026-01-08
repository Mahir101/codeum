// LC 61: Rotate List | LC 82/83: Remove Duplicates from Sorted List
#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 61: Rotate List by k
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = 1;
    ListNode* tail = head;
    while (tail->next) { len++; tail = tail->next; }
    k %= len;
    if (k == 0) return head;
    tail->next = head;  // Make circular
    for (int i = 0; i < len - k; i++) tail = tail->next;
    head = tail->next;
    tail->next = nullptr;
    return head;
}

// LC 83: Remove Duplicates (keep one)
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) curr->next = curr->next->next;
        else curr = curr->next;
    }
    return head;
}

// LC 82: Remove Duplicates II (remove all duplicates)
ListNode* deleteDuplicatesII(ListNode* head) {
    ListNode dummy(0); dummy.next = head;
    ListNode* prev = &dummy;
    while (head) {
        if (head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) head = head->next;
            prev->next = head->next;
        } else prev = prev->next;
        head = head->next;
    }
    return dummy.next;
}

int main() { cout << "Rotate and Remove Duplicates\n"; return 0; }
