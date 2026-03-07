// In-Place Reversal of Linked List Pattern
// LC 206: Reverse List | LC 92: Reverse Between | LC 25: Reverse in K-Groups
#include <iostream>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 206: Reverse Entire List
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) { ListNode* next = head->next; head->next = prev; prev = head; head = next; }
    return prev;
}

// LC 92: Reverse from position left to right
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
    ListNode dummy(0); dummy.next = head;
    ListNode* prev = &dummy;
    for (int i = 1; i < left; i++) prev = prev->next;
    ListNode* curr = prev->next;
    for (int i = 0; i < right - left; i++) {
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy.next;
}

// LC 24: Swap Nodes in Pairs
ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0); dummy.next = head;
    ListNode* prev = &dummy;
    while (prev->next && prev->next->next) {
        ListNode *first = prev->next, *second = prev->next->next;
        prev->next = second;
        first->next = second->next;
        second->next = first;
        prev = first;
    }
    return dummy.next;
}

int main() { cout << "In-Place Linked List Reversal Pattern\n"; return 0; }
