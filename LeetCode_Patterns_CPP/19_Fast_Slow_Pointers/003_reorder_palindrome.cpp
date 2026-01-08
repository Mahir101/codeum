// LC 143: Reorder List | LC 234: Palindrome Linked List
#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// Find middle, reverse second half, merge alternately
void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }
    ListNode *prev = nullptr, *curr = slow->next;
    slow->next = nullptr;
    while (curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    ListNode *first = head, *second = prev;
    while (second) {
        ListNode *t1 = first->next, *t2 = second->next;
        first->next = second; second->next = t1;
        first = t1; second = t2;
    }
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }
    ListNode *prev = nullptr, *curr = slow->next;
    while (curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    ListNode *p1 = head, *p2 = prev;
    while (p2) { if (p1->val != p2->val) return false; p1 = p1->next; p2 = p2->next; }
    return true;
}

int main() { cout << "Reorder and Palindrome List\n"; return 0; }
