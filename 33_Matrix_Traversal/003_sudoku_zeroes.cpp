// LC 36: Valid Sudoku | LC 48: Rotate Image | LC 73: Set Matrix Zeroes
#include <iostream>
#include <vector>
using namespace std;

// LC 36: Valid Sudoku
bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> rows(9), cols(9), boxes(9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                int bit = 1 << num;
                int box = (i / 3) * 3 + j / 3;
                if ((rows[i] | cols[j] | boxes[box]) & bit) return false;
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }
    }
    return true;
}

// LC 73: Set Matrix Zeroes (O(1) space)
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;
    
    for (int j = 0; j < n; j++) if (matrix[0][j] == 0) firstRowZero = true;
    for (int i = 0; i < m; i++) if (matrix[i][0] == 0) firstColZero = true;
    
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) { matrix[i][0] = 0; matrix[0][j] = 0; }
    
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
    
    if (firstRowZero) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    if (firstColZero) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}

int main() { cout << "Matrix validation and manipulation\n"; return 0; }
