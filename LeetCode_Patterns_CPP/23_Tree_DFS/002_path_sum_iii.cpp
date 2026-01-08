// LC 437: Path Sum III | LC 687: Longest Univalue Path
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 437: Path Sum III (any path, prefix sum)
int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long, int> prefixCount;
    prefixCount[0] = 1;
    int count = 0;
    function<void(TreeNode*, long)> dfs = [&](TreeNode* node, long currSum) {
        if (!node) return;
        currSum += node->val;
        if (prefixCount.count(currSum - targetSum)) count += prefixCount[currSum - targetSum];
        prefixCount[currSum]++;
        dfs(node->left, currSum);
        dfs(node->right, currSum);
        prefixCount[currSum]--;
    };
    dfs(root, 0);
    return count;
}

// LC 687: Longest Univalue Path
int longestUnivaluePath(TreeNode* root) {
    int maxLen = 0;
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        int left = dfs(node->left), right = dfs(node->right);
        int arrowLeft = 0, arrowRight = 0;
        if (node->left && node->left->val == node->val) arrowLeft = left + 1;
        if (node->right && node->right->val == node->val) arrowRight = right + 1;
        maxLen = max(maxLen, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    };
    dfs(root);
    return maxLen;
}

int main() { cout << "Path Sum III and Longest Univalue Path\n"; return 0; }
