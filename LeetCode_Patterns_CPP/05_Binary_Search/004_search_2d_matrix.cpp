// LC 74/240: Search 2D Matrix | Pattern: Binary Search on Matrix
#include <iostream>
#include <vector>
using namespace std;

// LC 74: Search sorted matrix (treat as 1D)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m * n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int val = matrix[mid / n][mid % n];
        if (val == target) return true;
        if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

// LC 240: Search matrix with row/col sorted (staircase)
bool searchMatrixII(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if (matrix[r][c] == target) return true;
        if (matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

int main() {
    vector<vector<int>> m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << "Search 3: " << searchMatrix(m, 3) << endl;
    return 0;
}
