// LC 2013: Detect Squares | LC 149: Max Points on a Line
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// LC 2013: Detect Squares
class DetectSquares {
    unordered_map<long long, int> points;
    
    long long hash(int x, int y) { return (long long)x * 100001 + y; }
public:
    void add(vector<int> point) { points[hash(point[0], point[1])]++; }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], result = 0;
        for (auto& [h, cnt] : points) {
            int x2 = h / 100001, y2 = h % 100001;
            if (abs(x2 - x1) != abs(y2 - y1) || x1 == x2) continue;
            result += cnt * points[hash(x1, y2)] * points[hash(x2, y1)];
        }
        return result;
    }
};

// LC 149: Max Points on a Line (GCD for slope)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<string, int> slopes;
        int maxLocal = 0;
        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            int g = gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;
            if (dx < 0) { dx = -dx; dy = -dy; }
            else if (dx == 0) dy = abs(dy);
            string key = to_string(dx) + "_" + to_string(dy);
            maxLocal = max(maxLocal, ++slopes[key]);
        }
        result = max(result, maxLocal + 1);
    }
    return result;
}

int main() {
    vector<vector<int>> pts = {{1,1}, {2,2}, {3,3}};
    cout << "Max points on line: " << maxPoints(pts) << endl;
    return 0;
}
