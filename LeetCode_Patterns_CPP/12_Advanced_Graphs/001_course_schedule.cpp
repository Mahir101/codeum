// LC 207: Course Schedule | Pattern: Topological Sort (Cycle Detection)
// Time: O(V+E) | Space: O(V+E)
// Recognition: "Can finish all tasks given prerequisites"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
    int count = 0;
    while (!q.empty()) {
        int course = q.front(); q.pop();
        count++;
        for (int next : graph[course]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }
    return count == numCourses;
}

int main() {
    vector<vector<int>> prereqs = {{1,0}, {0,1}};
    cout << "Can finish (cycle): " << canFinish(2, prereqs) << endl;
    prereqs = {{1,0}};
    cout << "Can finish (no cycle): " << canFinish(2, prereqs) << endl;
    return 0;
}
