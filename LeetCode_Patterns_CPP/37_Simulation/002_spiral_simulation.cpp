// LC 54: Spiral Matrix | LC 885: Spiral Matrix III
#include <iostream>
#include <vector>
using namespace std;

// LC 885: Spiral Matrix III (starting from (r, c))
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> result;
    int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
    int r = rStart, c = cStart, len = 0, d = 0;
    result.push_back({r, c});
    
    while ((int)result.size() < rows * cols) {
        if (d == 0 || d == 2) len++;
        for (int i = 0; i < len; i++) {
            r += dr[d]; c += dc[d];
            if (r >= 0 && r < rows && c >= 0 && c < cols)
                result.push_back({r, c});
        }
        d = (d + 1) % 4;
    }
    return result;
}

// LC 59: Spiral Matrix II (generate n x n)
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int top = 0, bottom = n - 1, left = 0, right = n - 1, num = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) result[top][j] = num++;
        top++;
        for (int i = top; i <= bottom; i++) result[i][right] = num++;
        right--;
        for (int j = right; j >= left; j--) result[bottom][j] = num++;
        bottom--;
        for (int i = bottom; i >= top; i--) result[i][left] = num++;
        left++;
    }
    return result;
}

int main() {
    auto matrix = generateMatrix(3);
    cout << "Generated 3x3 spiral matrix\n";
    return 0;
}
