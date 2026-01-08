// LC 19: Remove Nth Node From End | LC 86: Partition List
#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 19: Remove Nth Node From End (Two Pointers)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0); dummy.next = head;
    ListNode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) { fast = fast->next; slow = slow->next; }
    slow->next = slow->next->next;
    return dummy.next;
}

// LC 86: Partition List (values < x before values >= x)
ListNode* partition(ListNode* head, int x) {
    ListNode lessHead(0), greaterHead(0);
    ListNode *less = &lessHead, *greater = &greaterHead;
    while (head) {
        if (head->val < x) { less->next = head; less = less->next; }
        else { greater->next = head; greater = greater->next; }
        head = head->next;
    }
    greater->next = nullptr;
    less->next = greaterHead.next;
    return lessHead.next;
}

// LC 328: Odd Even Linked List
ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *odd = head, *even = head->next, *evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() { cout << "Linked list partitioning patterns\n"; return 0; }
