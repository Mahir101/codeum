// LC 1136: Parallel Courses | LC 2050: Parallel Courses III
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LC 1136: Minimum Semesters to Complete All Courses
int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    for (auto& r : relations) { graph[r[0]].push_back(r[1]); indegree[r[1]]++; }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indegree[i] == 0) q.push(i);
    int semesters = 0, completed = 0;
    while (!q.empty()) {
        semesters++;
        int sz = q.size();
        while (sz--) {
            int course = q.front(); q.pop();
            completed++;
            for (int next : graph[course])
                if (--indegree[next] == 0) q.push(next);
        }
    }
    return completed == n ? semesters : -1;
}

// LC 2050: Parallel Courses III (with time per course)
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0), dist(n + 1, 0);
    for (auto& r : relations) { graph[r[0]].push_back(r[1]); indegree[r[1]]++; }
    queue<int> q;
    for (int i = 1; i <= n; i++) { dist[i] = time[i - 1]; if (indegree[i] == 0) q.push(i); }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            dist[v] = max(dist[v], dist[u] + time[v - 1]);
            if (--indegree[v] == 0) q.push(v);
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main() { cout << "Parallel Courses with dependencies\n"; return 0; }
