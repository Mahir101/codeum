// LC 124: Binary Tree Maximum Path Sum
// Pattern: Post-order with global max tracking
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

class Solution {
    int maxSum = INT_MIN;
    
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        maxSum = max(maxSum, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main() { cout << "Max path sum - post-order with global tracking\n"; return 0; }
