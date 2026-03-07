// LC 104: Maximum Depth of Binary Tree | Pattern: DFS/BFS Tree Traversal
// Time: O(n) | Space: O(h)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

int maxDepthDFS(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepthDFS(root->left), maxDepthDFS(root->right));
}

int maxDepthBFS(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q; q.push(root);
    int depth = 0;
    while (!q.empty()) {
        depth++;
        int sz = q.size();
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}

int main() { cout << "Max depth - DFS recursive or BFS iterative\n"; return 0; }
