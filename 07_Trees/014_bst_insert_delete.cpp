// LC 450: Delete Node in BST | LC 701: Insert into BST | LC 700: Search in BST
#include <iostream>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 700: Search in BST
TreeNode* searchBST(TreeNode* root, int val) {
    while (root && root->val != val)
        root = val < root->val ? root->left : root->right;
    return root;
}

// LC 701: Insert into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

// LC 450: Delete Node in BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* minNode = root->right;
        while (minNode->left) minNode = minNode->left;
        root->val = minNode->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

int main() { cout << "BST Insert, Search, Delete\n"; return 0; }
