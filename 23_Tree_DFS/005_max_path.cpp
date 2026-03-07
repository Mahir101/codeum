// LC 124: Binary Tree Maximum Path Sum | LC 1372: Longest ZigZag Path
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 124: Maximum Path Sum (any path)
class Solution124 {
    int maxSum = INT_MIN;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        maxSum = max(maxSum, left + right + node->val);
        return max(left, right) + node->val;
    }
    
public:
    int maxPathSum(TreeNode* root) { dfs(root); return maxSum; }
};

// LC 1372: Longest ZigZag Path
class Solution1372 {
    int maxLen = 0;
    
    void dfs(TreeNode* node, bool isLeft, int len) {
        if (!node) return;
        maxLen = max(maxLen, len);
        if (isLeft) {
            dfs(node->left, true, 1);
            dfs(node->right, false, len + 1);
        } else {
            dfs(node->left, true, len + 1);
            dfs(node->right, false, 1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);
        return maxLen;
    }
};

// LC 298: Binary Tree Longest Consecutive Sequence
class Solution298 {
    int maxLen = 0;
    
    void dfs(TreeNode* node, TreeNode* parent, int len) {
        if (!node) return;
        len = (parent && node->val == parent->val + 1) ? len + 1 : 1;
        maxLen = max(maxLen, len);
        dfs(node->left, node, len);
        dfs(node->right, node, len);
    }
    
public:
    int longestConsecutive(TreeNode* root) { dfs(root, nullptr, 0); return maxLen; }
};

int main() { cout << "Tree path problems\n"; return 0; }
