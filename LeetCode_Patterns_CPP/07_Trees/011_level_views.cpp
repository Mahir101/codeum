// LC 199: Binary Tree Right Side View | LC 637: Average of Levels
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 199: Right Side View (rightmost at each level)
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) result.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

// LC 637: Average of Levels
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    if (!root) return result;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        double sum = 0;
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(sum / sz);
    }
    return result;
}

int main() { cout << "Level-based tree views\n"; return 0; }
