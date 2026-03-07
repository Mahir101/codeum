// LC 241: Different Ways to Add Parentheses | LC 95: Unique BSTs II
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 241: Different Ways to Add Parentheses
vector<int> diffWaysToCompute(string expression) {
    vector<int> result;
    for (int i = 0; i < (int)expression.size(); i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i + 1));
            for (int l : left) {
                for (int r : right) {
                    if (c == '+') result.push_back(l + r);
                    else if (c == '-') result.push_back(l - r);
                    else result.push_back(l * r);
                }
            }
        }
    }
    if (result.empty()) result.push_back(stoi(expression));
    return result;
}

// LC 95: Unique Binary Search Trees II
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} };

vector<TreeNode*> generateTrees(int start, int end) {
    if (start > end) return {nullptr};
    vector<TreeNode*> result;
    for (int i = start; i <= end; i++) {
        auto leftTrees = generateTrees(start, i - 1);
        auto rightTrees = generateTrees(i + 1, end);
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n) { return n == 0 ? vector<TreeNode*>{} : generateTrees(1, n); }

int main() {
    auto ways = diffWaysToCompute("2*3-4*5");
    cout << "Ways: " << ways.size() << endl;
    return 0;
}
