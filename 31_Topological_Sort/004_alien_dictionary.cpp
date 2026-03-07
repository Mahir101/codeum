// LC 269: Alien Dictionary | Advanced Topological Sort
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// LC 269: Alien Dictionary
string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> indegree;
    
    for (auto& w : words)
        for (char c : w) indegree[c] = 0;
    
    for (int i = 0; i < (int)words.size() - 1; i++) {
        string& w1 = words[i], &w2 = words[i + 1];
        if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
        for (int j = 0; j < min(w1.size(), w2.size()); j++) {
            if (w1[j] != w2[j]) {
                if (!graph[w1[j]].count(w2[j])) {
                    graph[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                break;
            }
        }
    }
    
    queue<char> q;
    for (auto& [c, deg] : indegree) if (deg == 0) q.push(c);
    
    string result;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        result += c;
        for (char next : graph[c])
            if (--indegree[next] == 0) q.push(next);
    }
    
    return result.size() == indegree.size() ? result : "";
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Alien order: " << alienOrder(words) << endl;
    return 0;
}
