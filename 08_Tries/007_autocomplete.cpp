// LC 642: Design Search Autocomplete System
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class AutocompleteSystem {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        unordered_map<string, int> counts;
    };
    
    TrieNode* root = new TrieNode();
    TrieNode* curr = root;
    string prefix = "";
    
    void addSentence(const string& s, int times) {
        TrieNode* node = root;
        for (char c : s) {
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
            node->counts[s] += times;
        }
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < (int)sentences.size(); i++)
            addSentence(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            addSentence(prefix, 1);
            prefix = "";
            curr = root;
            return {};
        }
        prefix += c;
        if (!curr || !curr->children.count(c)) { curr = nullptr; return {}; }
        curr = curr->children[c];
        
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for (auto& [s, cnt] : curr->counts) {
            pq.push({cnt, s});
            if (pq.size() > 3) pq.pop();
        }
        vector<string> result;
        while (!pq.empty()) { result.push_back(pq.top().second); pq.pop(); }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<string> sentences = {"i love you", "island", "ironman", "i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem ac(sentences, times);
    auto r = ac.input('i');
    cout << "Results for 'i': " << r.size() << endl;
    return 0;
}
