// LC 332: Reconstruct Itinerary | Pattern: Hierholzer's Algorithm (Eulerian Path)
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    map<string, multiset<string>> graph;
    vector<string> result;
    
    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next);
        }
        result.push_back(airport);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) graph[t[0]].insert(t[1]);
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution sol;
    auto itinerary = sol.findItinerary(tickets);
    cout << "Itinerary: ";
    for (auto& s : itinerary) cout << s << " ";
    cout << endl;
    return 0;
}
