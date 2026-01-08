// LC 102: Binary Tree Level Order | LC 103: Zigzag | LC 107: Bottom-up
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q; q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            int idx = leftToRight ? i : sz - 1 - i;
            level[idx] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
        leftToRight = !leftToRight;
    }
    return result;
}

int main() { cout << "Level order BFS traversals\n"; return 0; }
