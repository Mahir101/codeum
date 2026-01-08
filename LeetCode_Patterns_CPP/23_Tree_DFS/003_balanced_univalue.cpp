// LC 110: Balanced Binary Tree | LC 250: Count Univalue Subtrees
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 110: Balanced Binary Tree
bool isBalanced(TreeNode* root) {
    function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int left = height(node->left);
        if (left == -1) return -1;
        int right = height(node->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    };
    return height(root) != -1;
}

// LC 250: Count Univalue Subtrees
int countUnivalSubtrees(TreeNode* root) {
    int count = 0;
    function<bool(TreeNode*, int)> isUnival = [&](TreeNode* node, int val) -> bool {
        if (!node) return true;
        if (!isUnival(node->left, node->val) | !isUnival(node->right, node->val)) return false;
        count++;
        return node->val == val;
    };
    isUnival(root, 0);
    return count;
}

int main() { cout << "Balanced Tree and Univalue Subtrees\n"; return 0; }
