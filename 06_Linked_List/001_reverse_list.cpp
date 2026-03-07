// LC 206: Reverse Linked List | Pattern: In-Place Reversal
// Time: O(n) | Space: O(1)
// Recognition: "Reverse order of linked list nodes"
#include <iostream>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main() { cout << "Reverse Linked List - iterative O(1) space\n"; return 0; }
