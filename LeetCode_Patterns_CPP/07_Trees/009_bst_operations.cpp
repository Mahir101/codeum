// LC 230: Kth Smallest in BST | LC 235: LCA of BST
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 230: Kth Smallest (Inorder traversal)
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    while (root || !stk.empty()) {
        while (root) { stk.push(root); root = root->left; }
        root = stk.top(); stk.pop();
        if (--k == 0) return root->val;
        root = root->right;
    }
    return -1;
}

// LC 235: LCA of BST (use BST property)
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}

int main() { cout << "BST operations - inorder traversal\n"; return 0; }
