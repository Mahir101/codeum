// LC 143: Reorder List | Pattern: Find Middle + Reverse + Merge
#include <iostream>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

void reorderList(ListNode* head) {
    if (!head || !head->next) return;
    // Find middle
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next; fast = fast->next->next;
    }
    // Reverse second half
    ListNode *prev = nullptr, *curr = slow->next;
    slow->next = nullptr;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev; prev = curr; curr = next;
    }
    // Merge alternately
    ListNode *first = head, *second = prev;
    while (second) {
        ListNode *tmp1 = first->next, *tmp2 = second->next;
        first->next = second; second->next = tmp1;
        first = tmp1; second = tmp2;
    }
}

int main() { cout << "Reorder list: find mid + reverse + merge\n"; return 0; }
