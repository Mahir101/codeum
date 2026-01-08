// LC 472: Concatenated Words | LC 139: Word Break with Trie
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    bool isEnd = false;
};

class Solution {
    TrieNode* root = new TrieNode();
    
    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool canForm(string& word, int start, int count, vector<int>& memo) {
        if (start == (int)word.size()) return count >= 2;
        if (memo[start] != -1) return memo[start];
        TrieNode* node = root;
        for (int i = start; i < (int)word.size(); i++) {
            if (!node->children[word[i] - 'a']) break;
            node = node->children[word[i] - 'a'];
            if (node->isEnd && canForm(word, i + 1, count + 1, memo))
                return memo[start] = true;
        }
        return memo[start] = false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto& w : words) if (!w.empty()) insert(w);
        vector<string> result;
        for (auto& w : words) {
            if (w.empty()) continue;
            vector<int> memo(w.size(), -1);
            if (canForm(w, 0, 0, memo)) result.push_back(w);
        }
        return result;
    }
};

int main() {
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    Solution sol;
    auto result = sol.findAllConcatenatedWordsInADict(words);
    cout << "Concatenated words: " << result.size() << endl;
    return 0;
}
