// LC 160: Intersection of Two Lists | LC 2: Add Two Numbers
#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 160: Intersection of Two Linked Lists
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    return pA;
}

// LC 2: Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); ListNode* curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return dummy.next;
}

// LC 445: Add Two Numbers II (most significant first)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) { ListNode* next = head->next; head->next = prev; prev = head; head = next; }
    return prev;
}

ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1); l2 = reverseList(l2);
    ListNode* result = addTwoNumbers(l1, l2);
    return reverseList(result);
}

int main() { cout << "Intersection and Add Two Numbers\n"; return 0; }
