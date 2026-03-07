// LC 863: All Nodes Distance K | LC 314: Binary Tree Vertical Order
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

// LC 863: All Nodes Distance K (BFS from target with parent pointers)
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node->left) { parent[node->left] = node; q.push(node->left); }
        if (node->right) { parent[node->right] = node; q.push(node->right); }
    }
    unordered_set<TreeNode*> visited;
    q.push(target); visited.insert(target);
    while (!q.empty() && k > 0) {
        int sz = q.size(); k--;
        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            if (node->left && !visited.count(node->left)) { visited.insert(node->left); q.push(node->left); }
            if (node->right && !visited.count(node->right)) { visited.insert(node->right); q.push(node->right); }
            if (parent.count(node) && !visited.count(parent[node])) { visited.insert(parent[node]); q.push(parent[node]); }
        }
    }
    vector<int> result;
    while (!q.empty()) { result.push_back(q.front()->val); q.pop(); }
    return result;
}

int main() { cout << "Nodes at Distance K\n"; return 0; }
