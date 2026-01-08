// LC 572: Subtree of Another Tree | LC 100: Same Tree | LC 101: Symmetric Tree
#include <iostream>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 100: Same Tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// LC 572: Subtree of Another Tree
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// LC 101: Symmetric Tree
bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right || left->val != right->val) return false;
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return root == nullptr || isMirror(root->left, root->right);
}

int main() { cout << "Tree comparison patterns\n"; return 0; }
