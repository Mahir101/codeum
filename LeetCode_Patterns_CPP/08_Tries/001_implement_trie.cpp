// LC 208: Implement Trie | Pattern: Prefix Tree
// Time: O(L) per operation | Space: O(total chars)
// Recognition: "Prefix-based string storage/search"
#include <iostream>
#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* children[26] = {};
        bool isEnd = false;
    };
    Node* root = new Node();
public:
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new Node();
            node = node->children[i];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        Node* node = find(word);
        return node && node->isEnd;
    }
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
private:
    Node* find(string& s) {
        Node* node = root;
        for (char c : s) {
            int i = c - 'a';
            if (!node->children[i]) return nullptr;
            node = node->children[i];
        }
        return node;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search 'apple': " << trie.search("apple") << endl;
    cout << "StartsWith 'app': " << trie.startsWith("app") << endl;
    return 0;
}
