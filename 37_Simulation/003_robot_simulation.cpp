// LC 657: Robot Return to Origin | LC 874: Walking Robot Simulation
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// LC 657: Robot Return to Origin
bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
        if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == 'L') x--;
        else if (c == 'R') x++;
    }
    return x == 0 && y == 0;
}

// LC 874: Walking Robot Simulation
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    set<pair<int, int>> obstacleSet;
    for (auto& o : obstacles) obstacleSet.insert({o[0], o[1]});
    
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int x = 0, y = 0, dir = 0;
    int maxDist = 0;
    
    for (int cmd : commands) {
        if (cmd == -2) dir = (dir + 3) % 4;  // Turn left
        else if (cmd == -1) dir = (dir + 1) % 4;  // Turn right
        else {
            for (int i = 0; i < cmd; i++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (obstacleSet.count({nx, ny})) break;
                x = nx; y = ny;
                maxDist = max(maxDist, x*x + y*y);
            }
        }
    }
    return maxDist;
}

// LC 165: Compare Version Numbers
int compareVersion(string version1, string version2) {
    int i = 0, j = 0;
    while (i < (int)version1.size() || j < (int)version2.size()) {
        int v1 = 0, v2 = 0;
        while (i < (int)version1.size() && version1[i] != '.') v1 = v1 * 10 + (version1[i++] - '0');
        while (j < (int)version2.size() && version2[j] != '.') v2 = v2 * 10 + (version2[j++] - '0');
        if (v1 < v2) return -1;
        if (v1 > v2) return 1;
        i++; j++;
    }
    return 0;
}

int main() {
    cout << "Robot 'UDLR': " << judgeCircle("UDLR") << endl;
    return 0;
}
