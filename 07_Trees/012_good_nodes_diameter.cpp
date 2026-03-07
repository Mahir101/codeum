// LC 1448: Count Good Nodes | LC 543: Diameter of Binary Tree
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 1448: Count Good Nodes (val >= all ancestors)
int countGoodNodes(TreeNode* node, int maxSoFar) {
    if (!node) return 0;
    int count = (node->val >= maxSoFar) ? 1 : 0;
    int newMax = max(maxSoFar, node->val);
    return count + countGoodNodes(node->left, newMax) + countGoodNodes(node->right, newMax);
}

int goodNodes(TreeNode* root) { return countGoodNodes(root, root ? root->val : 0); }

// LC 543: Diameter of Binary Tree
int diameter = 0;

int depth(TreeNode* node) {
    if (!node) return 0;
    int left = depth(node->left);
    int right = depth(node->right);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    diameter = 0;
    depth(root);
    return diameter;
}

int main() { cout << "Tree path problems\n"; return 0; }
