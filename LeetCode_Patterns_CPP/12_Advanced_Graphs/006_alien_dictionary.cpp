// LC 269: Alien Dictionary | Pattern: Topological Sort from Constraints
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;
    
    // Initialize all characters
    for (string& w : words) for (char c : w) indegree[c] = 0;
    
    // Build graph from word comparisons
    for (int i = 0; i < (int)words.size() - 1; i++) {
        string& w1 = words[i], &w2 = words[i + 1];
        int minLen = min(w1.size(), w2.size());
        
        // Invalid: prefix is longer
        if (w1.size() > w2.size() && w1.substr(0, minLen) == w2) return "";
        
        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                if (!graph[w1[j]].count(w2[j])) {
                    graph[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }
    
    // Topological sort
    queue<char> q;
    for (auto& [c, deg] : indegree) if (deg == 0) q.push(c);
    
    string result;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        result += c;
        for (char next : graph[c]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }
    
    return result.size() == indegree.size() ? result : "";
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Alien order: " << alienOrder(words) << endl;
    return 0;
}
