// LC 51: N-Queens | Pattern: Constraint Backtracking
// Time: O(n!) | Space: O(n)
// Recognition: "Place N queens with no attacks"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<bool> cols, diag1, diag2;
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) { result.push_back(board); return; }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row-col+n] || diag2[row+col]) continue;
            board[row][col] = 'Q';
            cols[col] = diag1[row-col+n] = diag2[row+col] = true;
            solve(row + 1, n, board, result);
            board[row][col] = '.';
            cols[col] = diag1[row-col+n] = diag2[row+col] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        cols.assign(n, false); diag1.assign(2*n, false); diag2.assign(2*n, false);
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, result);
        return result;
    }
};

int main() {
    Solution sol;
    cout << "N-Queens (4): " << sol.solveNQueens(4).size() << " solutions\n";
    return 0;
}
