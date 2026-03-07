// LC 98: Validate BST | Pattern: Inorder / Range Validation
// Time: O(n) | Space: O(h)
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) && 
           isValidBST(root->right, root->val, maxVal);
}

int main() { cout << "Validate BST - pass min/max bounds down\n"; return 0; }
