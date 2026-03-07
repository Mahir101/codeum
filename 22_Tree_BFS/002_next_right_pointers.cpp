// LC 116/117: Populating Next Right Pointers | LC 429: N-ary Level Order
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node { int val; Node *left, *right, *next; Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {} };

// LC 116: Perfect Binary Tree - O(1) space
Node* connect(Node* root) {
    if (!root) return nullptr;
    Node* leftmost = root;
    while (leftmost->left) {
        Node* head = leftmost;
        while (head) {
            head->left->next = head->right;
            if (head->next) head->right->next = head->next->left;
            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}

// LC 117: Any Binary Tree - O(1) space
Node* connectII(Node* root) {
    Node* curr = root;
    while (curr) {
        Node dummy(0); Node* tail = &dummy;
        while (curr) {
            if (curr->left) { tail->next = curr->left; tail = tail->next; }
            if (curr->right) { tail->next = curr->right; tail = tail->next; }
            curr = curr->next;
        }
        curr = dummy.next;
    }
    return root;
}

int main() { cout << "Populating Next Right Pointers\n"; return 0; }
