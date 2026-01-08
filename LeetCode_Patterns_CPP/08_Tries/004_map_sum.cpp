// LC 677: Map Sum Pairs | LC 1268: Search Suggestions System
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 677: Map Sum with prefix
class MapSum {
    struct TrieNode { int val = 0; unordered_map<char, TrieNode*> children; };
    TrieNode* root = new TrieNode();
    unordered_map<string, int> keyVals;
    
public:
    void insert(string key, int val) {
        int delta = val - keyVals[key];
        keyVals[key] = val;
        TrieNode* node = root;
        for (char c : key) {
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
            node->val += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c]) return 0;
            node = node->children[c];
        }
        return node->val;
    }
};

// LC 1268: Search Suggestions System
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> result;
    string prefix = "";
    int start = 0;
    for (char c : searchWord) {
        prefix += c;
        auto it = lower_bound(products.begin() + start, products.end(), prefix);
        start = it - products.begin();
        vector<string> suggestions;
        for (int i = start; i < (int)products.size() && suggestions.size() < 3 && 
             products[i].substr(0, prefix.size()) == prefix; i++)
            suggestions.push_back(products[i]);
        result.push_back(suggestions);
    }
    return result;
}

int main() {
    MapSum ms; ms.insert("apple", 3); ms.insert("app", 2);
    cout << "Sum 'ap': " << ms.sum("ap") << endl;
    return 0;
}
