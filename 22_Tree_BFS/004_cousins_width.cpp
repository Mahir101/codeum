// LC 993: Cousins in Binary Tree | LC 662: Maximum Width of Binary Tree
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 993: Cousins in Binary Tree
bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        bool foundX = false, foundY = false;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            if (node->left && node->right) {
                if ((node->left->val == x && node->right->val == y) ||
                    (node->left->val == y && node->right->val == x)) return false;
            }
            if (node->val == x) foundX = true;
            if (node->val == y) foundY = true;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if (foundX && foundY) return true;
        if (foundX || foundY) return false;
    }
    return false;
}

// LC 662: Maximum Width of Binary Tree
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    unsigned long long maxWidth = 0;
    while (!q.empty()) {
        int sz = q.size();
        unsigned long long left = q.front().second, right = left;
        while (sz--) {
            auto [node, idx] = q.front(); q.pop();
            right = idx;
            if (node->left) q.push({node->left, 2 * idx});
            if (node->right) q.push({node->right, 2 * idx + 1});
        }
        maxWidth = max(maxWidth, right - left + 1);
    }
    return maxWidth;
}

int main() { cout << "Cousins and Width of Binary Tree\n"; return 0; }
