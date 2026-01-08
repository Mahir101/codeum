// Matrix Traversal Pattern (4/8 directions, spiral, diagonal)
// LC 54: Spiral Matrix | LC 498: Diagonal Traverse | LC 1329: Sort Matrix Diagonally
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dirs4[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int dirs8[8][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

// LC 54: Spiral Matrix
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) result.push_back(matrix[top][j]); top++;
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]); right--;
        if (top <= bottom) { for (int j = right; j >= left; j--) result.push_back(matrix[bottom][j]); bottom--; }
        if (left <= right) { for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]); left++; }
    }
    return result;
}

// LC 498: Diagonal Traverse
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> result;
    for (int d = 0; d < m + n - 1; d++) {
        vector<int> diag;
        int r = d < n ? 0 : d - n + 1;
        int c = d < n ? d : n - 1;
        while (r < m && c >= 0) { diag.push_back(mat[r][c]); r++; c--; }
        if (d % 2 == 0) reverse(diag.begin(), diag.end());
        for (int x : diag) result.push_back(x);
    }
    return result;
}

// LC 766: Toeplitz Matrix
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] != matrix[i-1][j-1]) return false;
    return true;
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    auto spiral = spiralOrder(mat);
    cout << "Spiral: "; for (int x : spiral) cout << x << " "; cout << endl;
    return 0;
}
