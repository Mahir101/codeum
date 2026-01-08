// LC 36: Valid Sudoku
// Pattern: Hash Set for Rows/Cols/Boxes
// Time: O(81) = O(1) | Space: O(81) = O(1)
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            
            int boxIdx = (i / 3) * 3 + j / 3;
            
            if (rows[i].count(c) || cols[j].count(c) || boxes[boxIdx].count(c)) {
                return false;
            }
            
            rows[i].insert(c);
            cols[j].insert(c);
            boxes[boxIdx].insert(c);
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << "Valid Sudoku: " << (isValidSudoku(board) ? "Yes" : "No") << endl;
    return 0;
}
