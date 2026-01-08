// Simulation Pattern
// LC 6: Zigzag Conversion | LC 68: Text Justification | LC 54: Spiral Matrix
// LC 289: Game of Life | LC 874: Walking Robot | LC 1823: Find Winner
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 6: Zigzag Conversion
string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> rows(min(numRows, (int)s.size()));
    int curRow = 0, goingDown = false;
    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }
    string result;
    for (auto& row : rows) result += row;
    return result;
}

// LC 289: Game of Life
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                    live += board[ni][nj] & 1;
            }
            if (board[i][j] == 1 && (live == 2 || live == 3)) board[i][j] |= 2;
            if (board[i][j] == 0 && live == 3) board[i][j] |= 2;
        }
    }
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) board[i][j] >>= 1;
}

// LC 1823: Find the Winner of Circular Game (Josephus)
int findTheWinner(int n, int k) {
    int winner = 0;
    for (int i = 2; i <= n; i++) winner = (winner + k) % i;
    return winner + 1;
}

int main() {
    cout << "Zigzag 'PAYPALISHIRING' (3): " << convert("PAYPALISHIRING", 3) << endl;
    cout << "Josephus(5,2): " << findTheWinner(5, 2) << endl;
    return 0;
}
