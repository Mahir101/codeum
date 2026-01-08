// LC 25: Reverse Nodes in k-Group
#include <iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 25: Reverse Nodes in k-Group
ListNode* reverseKGroup(ListNode* head, int k) {
    // Count nodes
    int count = 0;
    ListNode* curr = head;
    while (curr) { count++; curr = curr->next; }
    
    ListNode dummy(0); dummy.next = head;
    ListNode* prevGroup = &dummy;
    
    while (count >= k) {
        ListNode* prev = nullptr;
        ListNode* curr = prevGroup->next;
        ListNode* groupStart = curr;
        
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        prevGroup->next = prev;
        groupStart->next = curr;
        prevGroup = groupStart;
        count -= k;
    }
    return dummy.next;
}

// Reverse every alternate k nodes
ListNode* reverseAlternateK(ListNode* head, int k) {
    if (!head) return nullptr;
    
    ListNode* prev = nullptr;
    ListNode* curr = head;
    int count = 0;
    
    while (curr && count < k) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    head->next = curr;
    count = 0;
    while (curr && count < k - 1) { curr = curr->next; count++; }
    
    if (curr) curr->next = reverseAlternateK(curr->next, k);
    return prev;
}

int main() { cout << "Reverse K-Group patterns\n"; return 0; }
