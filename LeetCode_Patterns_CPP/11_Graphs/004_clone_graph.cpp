// LC 133: Clone Graph | Pattern: DFS/BFS with HashMap
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

class Solution {
    unordered_map<Node*, Node*> cloned;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (cloned.count(node)) return cloned[node];
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        for (Node* neighbor : node->neighbors)
            copy->neighbors.push_back(cloneGraph(neighbor));
        return copy;
    }
};

int main() { cout << "Clone graph - DFS with memoization\n"; return 0; }
