// Fast & Slow Pointers Pattern (Floyd's Tortoise and Hare)
// LC 141: Linked List Cycle | LC 142: Cycle Start | LC 876: Middle of List
// LC 234: Palindrome List | LC 287: Find Duplicate
#include <iostream>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 876: Middle of Linked List
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow;
}

// LC 141: Has Cycle
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// LC 142: Find Cycle Start
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) { slow = slow->next; fast = fast->next; }
            return slow;
        }
    }
    return nullptr;
}

// LC 202: Happy Number (using fast/slow)
int getNext(int n) { int sum = 0; while (n) { sum += (n%10)*(n%10); n /= 10; } return sum; }
bool isHappy(int n) {
    int slow = n, fast = getNext(n);
    while (fast != 1 && slow != fast) { slow = getNext(slow); fast = getNext(getNext(fast)); }
    return fast == 1;
}

int main() { cout << "Fast & Slow Pointers Pattern\n"; return 0; }
