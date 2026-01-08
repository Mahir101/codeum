// LC 109: Convert Sorted List to BST | LC 1382: Balance a BST
#include <iostream>
#include <vector>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 109: Sorted List to BST
ListNode* curr;
TreeNode* sortedListToBST(int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* left = sortedListToBST(start, mid - 1);
    TreeNode* root = new TreeNode(curr->val);
    curr = curr->next;
    root->left = left;
    root->right = sortedListToBST(mid + 1, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    int size = 0;
    for (ListNode* n = head; n; n = n->next) size++;
    curr = head;
    return sortedListToBST(0, size - 1);
}

// LC 1382: Balance a BST
void inorder(TreeNode* node, vector<int>& nodes) {
    if (!node) return;
    inorder(node->left, nodes);
    nodes.push_back(node->val);
    inorder(node->right, nodes);
}

TreeNode* buildBalanced(vector<int>& nodes, int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = (lo + hi) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);
    root->left = buildBalanced(nodes, lo, mid - 1);
    root->right = buildBalanced(nodes, mid + 1, hi);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;
    inorder(root, nodes);
    return buildBalanced(nodes, 0, nodes.size() - 1);
}

int main() { cout << "Sorted List to BST and Balance BST\n"; return 0; }
