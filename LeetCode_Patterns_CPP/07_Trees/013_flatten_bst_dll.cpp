// LC 114: Flatten Binary Tree to Linked List | LC 426: BST to Doubly Linked List
#include <iostream>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 114: Flatten to Linked List (Morris-like)
void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* rightmost = curr->left;
            while (rightmost->right) rightmost = rightmost->right;
            rightmost->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

// LC 426: BST to Sorted Doubly Linked List
class Node { public: int val; Node *left, *right; Node(int x) : val(x), left(nullptr), right(nullptr) {} };

Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    Node *head = nullptr, *prev = nullptr;
    function<void(Node*)> inorder = [&](Node* node) {
        if (!node) return;
        inorder(node->left);
        if (!prev) head = node;
        else { prev->right = node; node->left = prev; }
        prev = node;
        inorder(node->right);
    };
    inorder(root);
    head->left = prev;
    prev->right = head;
    return head;
}

int main() { cout << "Flatten tree to list\n"; return 0; }
