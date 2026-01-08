// LC 968: Binary Tree Cameras | LC 337: House Robber III
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 968: Binary Tree Cameras (greedy post-order)
int minCameraCover(TreeNode* root) {
    int cameras = 0;
    // 0: needs camera, 1: has camera, 2: covered
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 2;  // null is covered
        int left = dfs(node->left), right = dfs(node->right);
        if (left == 0 || right == 0) { cameras++; return 1; }
        if (left == 1 || right == 1) return 2;
        return 0;
    };
    if (dfs(root) == 0) cameras++;
    return cameras;
}

// LC 337: House Robber III
pair<int, int> robDFS(TreeNode* node) {
    if (!node) return {0, 0};
    auto [leftRob, leftSkip] = robDFS(node->left);
    auto [rightRob, rightSkip] = robDFS(node->right);
    int rob = node->val + leftSkip + rightSkip;
    int skip = max(leftRob, leftSkip) + max(rightRob, rightSkip);
    return {rob, skip};
}

int rob(TreeNode* root) {
    auto [robRoot, skipRoot] = robDFS(root);
    return max(robRoot, skipRoot);
}

int main() { cout << "Tree Cameras and House Robber III\n"; return 0; }
