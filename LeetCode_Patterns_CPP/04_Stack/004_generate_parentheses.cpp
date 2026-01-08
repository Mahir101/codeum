// LC 22: Generate Parentheses
// Pattern: Stack-like Backtracking
// Time: O(4^n/sqrt(n)) | Space: O(n)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int open, int close, int n, string& current, vector<string>& result) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        current += '(';
        generate(open + 1, close, n, current, result);
        current.pop_back();
    }
    if (close < open) {
        current += ')';
        generate(open, close + 1, n, current, result);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    generate(0, 0, n, current, result);
    return result;
}

int main() {
    auto result = generateParenthesis(3);
    cout << "Generate Parentheses (n=3): ";
    for (const string& s : result) cout << s << " ";
    cout << endl;
    return 0;
}
