// LC 226: Invert Binary Tree | Pattern: DFS Transformation
// Time: O(n) | Space: O(h)
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main() { cout << "Invert tree - swap children recursively\n"; return 0; }
