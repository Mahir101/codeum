// LC 25: Reverse Nodes in k-Group | Pattern: Segment Reversal
#include <iostream>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

ListNode* reverseKGroup(ListNode* head, int k) {
    // Check if we have k nodes
    ListNode* curr = head;
    for (int i = 0; i < k; i++) {
        if (!curr) return head;
        curr = curr->next;
    }
    // Reverse k nodes
    ListNode *prev = nullptr, *node = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = node->next;
        node->next = prev; prev = node; node = next;
    }
    head->next = reverseKGroup(node, k);
    return prev;
}

int main() { cout << "Reverse in k-groups\n"; return 0; }
