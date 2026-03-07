// LC 105: Construct Tree from Preorder and Inorder
// LC 106: Construct from Inorder and Postorder
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

class Solution {
    unordered_map<int, int> inMap;
    int preIdx = 0;
    
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, left, inMap[rootVal] - 1);
        root->right = build(preorder, inMap[rootVal] + 1, right);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); i++) inMap[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};

int main() { cout << "Construct tree from traversals\n"; return 0; }
