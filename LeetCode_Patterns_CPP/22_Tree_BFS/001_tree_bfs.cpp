// Tree BFS Pattern (Level Order Traversal)
// LC 102: Level Order | LC 103: Zigzag | LC 107: Bottom-Up | LC 637: Average
// LC 111: Minimum Depth | LC 116: Populating Next Right Pointers
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// Core BFS Template
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

// LC 111: Minimum Depth (first leaf node)
int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q; q.push(root);
    int depth = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            if (!node->left && !node->right) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        depth++;
    }
    return depth;
}

// LC 515: Find Largest Value in Each Row
vector<int> largestValues(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int size = q.size(), maxVal = INT_MIN;
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            maxVal = max(maxVal, node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(maxVal);
    }
    return result;
}

int main() { cout << "Tree BFS Pattern\n"; return 0; }
