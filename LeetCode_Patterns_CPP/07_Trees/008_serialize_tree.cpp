// LC 297: Serialize and Deserialize Binary Tree
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

class Codec {
public:
    // BFS Serialization
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        return result;
    }
    
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
            }
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->right = new TreeNode(stoi(item));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

int main() { cout << "Serialize/Deserialize tree - BFS level order\n"; return 0; }
