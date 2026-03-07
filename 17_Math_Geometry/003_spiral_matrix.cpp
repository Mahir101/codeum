// LC 54: Spiral Matrix | LC 59: Spiral Matrix II
#include <iostream>
#include <vector>
using namespace std;

// LC 54: Spiral Matrix (read)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) result.push_back(matrix[top][j]);
        top++;
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) result.push_back(matrix[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}

// LC 59: Spiral Matrix II (generate)
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int top = 0, bottom = n - 1, left = 0, right = n - 1, num = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) matrix[top][j] = num++;
        top++;
        for (int i = top; i <= bottom; i++) matrix[i][right] = num++;
        right--;
        for (int j = right; j >= left; j--) matrix[bottom][j] = num++;
        bottom--;
        for (int i = bottom; i >= top; i--) matrix[i][left] = num++;
        left++;
    }
    return matrix;
}

int main() {
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    auto spiral = spiralOrder(m);
    cout << "Spiral: "; for (int x : spiral) cout << x << " "; cout << endl;
    return 0;
}
