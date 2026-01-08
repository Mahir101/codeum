// LC 212: Word Search II | Pattern: Trie + Backtracking
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };
    TrieNode* root = new TrieNode();
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void buildTrie(vector<string>& words) {
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->word = w;
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if (!node->word.empty()) { result.push_back(node->word); node->word = ""; }
        board[i][j] = '#';
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < (int)board.size() && nj >= 0 && nj < (int)board[0].size())
                dfs(board, ni, nj, node, result);
        }
        board[i][j] = c;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        vector<string> result;
        for (int i = 0; i < (int)board.size(); i++)
            for (int j = 0; j < (int)board[0].size(); j++)
                dfs(board, i, j, root, result);
        return result;
    }
};

int main() { cout << "Word Search II - Trie + DFS backtracking\n"; return 0; }
