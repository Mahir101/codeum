// LC 841: Keys and Rooms | LC 1466: Reorder Routes
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 841: Keys and Rooms (DFS/BFS)
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    queue<int> q; q.push(0);
    visited[0] = true;
    int count = 1;
    
    while (!q.empty()) {
        int room = q.front(); q.pop();
        for (int key : rooms[room]) {
            if (!visited[key]) {
                visited[key] = true;
                count++;
                q.push(key);
            }
        }
    }
    return count == n;
}

// LC 1466: Reorder Routes to Make All Paths Lead to City Zero
int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, int>>> graph(n);  // {neighbor, direction}
    for (auto& c : connections) {
        graph[c[0]].push_back({c[1], 1});  // Original direction
        graph[c[1]].push_back({c[0], 0});  // Reverse direction
    }
    
    vector<bool> visited(n, false);
    queue<int> q; q.push(0);
    visited[0] = true;
    int changes = 0;
    
    while (!q.empty()) {
        int city = q.front(); q.pop();
        for (auto& [next, dir] : graph[city]) {
            if (!visited[next]) {
                visited[next] = true;
                changes += dir;  // Need to reorder if going away from 0
                q.push(next);
            }
        }
    }
    return changes;
}

int main() {
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    cout << "Can visit all: " << canVisitAllRooms(rooms) << endl;
    return 0;
}
