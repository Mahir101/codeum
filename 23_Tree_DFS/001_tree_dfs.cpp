// Tree DFS Pattern (Preorder, Inorder, Postorder)
// LC 112: Path Sum | LC 113: Path Sum II | LC 437: Path Sum III
// LC 129: Sum Root to Leaf | LC 257: Binary Tree Paths
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 112: Path Sum (root to leaf)
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return targetSum == root->val;
    return hasPathSum(root->left, targetSum - root->val) || 
           hasPathSum(root->right, targetSum - root->val);
}

// LC 113: All root-to-leaf paths with sum
void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& result) {
    if (!node) return;
    path.push_back(node->val);
    if (!node->left && !node->right && node->val == sum) result.push_back(path);
    findPaths(node->left, sum - node->val, path, result);
    findPaths(node->right, sum - node->val, path, result);
    path.pop_back();
}

// LC 129: Sum Root to Leaf Numbers
int sumNumbers(TreeNode* root, int num = 0) {
    if (!root) return 0;
    num = num * 10 + root->val;
    if (!root->left && !root->right) return num;
    return sumNumbers(root->left, num) + sumNumbers(root->right, num);
}

// LC 257: Binary Tree Paths (as strings)
void binaryTreePaths(TreeNode* node, string path, vector<string>& result) {
    if (!node) return;
    path += to_string(node->val);
    if (!node->left && !node->right) { result.push_back(path); return; }
    binaryTreePaths(node->left, path + "->", result);
    binaryTreePaths(node->right, path + "->", result);
}

int main() { cout << "Tree DFS Pattern\n"; return 0; }
