// LC 211: Design Add and Search Words | Pattern: Trie with Wildcard
#include <iostream>
#include <string>
using namespace std;

class WordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };
    TrieNode* root = new TrieNode();
    
    bool searchHelper(const string& word, int idx, TrieNode* node) {
        if (idx == (int)word.size()) return node->isEnd;
        char c = word[idx];
        if (c == '.') {
            for (auto child : node->children) {
                if (child && searchHelper(word, idx + 1, child)) return true;
            }
            return false;
        }
        if (!node->children[c - 'a']) return false;
        return searchHelper(word, idx + 1, node->children[c - 'a']);
    }
    
public:
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) { return searchHelper(word, 0, root); }
};

int main() {
    WordDictionary wd;
    wd.addWord("bad"); wd.addWord("dad");
    cout << "Search 'b.d': " << wd.search("b.d") << endl;
    return 0;
}
