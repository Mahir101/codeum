// LC 234: Palindrome Linked List | LC 138: Copy List with Random Pointer
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 234: Palindrome Linked List (O(1) space)
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    // Find middle
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }
    // Reverse second half
    ListNode *prev = nullptr, *curr = slow->next;
    while (curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    // Compare
    ListNode *first = head, *second = prev;
    while (second) {
        if (first->val != second->val) return false;
        first = first->next; second = second->next;
    }
    return true;
}

// LC 138: Copy List with Random Pointer (O(1) space interweaving)
struct Node { int val; Node *next, *random; Node(int x) : val(x), next(nullptr), random(nullptr) {} };

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    // Interweave: A -> A' -> B -> B' -> ...
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    // Set random pointers
    curr = head;
    while (curr) {
        if (curr->random) curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    // Separate lists
    Node dummy(0); Node* tail = &dummy;
    curr = head;
    while (curr) {
        tail->next = curr->next;
        tail = tail->next;
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return dummy.next;
}

int main() { cout << "Palindrome check and copy with random\n"; return 0; }
