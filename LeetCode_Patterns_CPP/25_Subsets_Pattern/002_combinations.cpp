// LC 77: Combinations | LC 216: Combination Sum III
#include <iostream>
#include <vector>
using namespace std;

// LC 77: Combinations (n choose k)
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> curr;
    function<void(int)> backtrack = [&](int start) {
        if ((int)curr.size() == k) { result.push_back(curr); return; }
        for (int i = start; i <= n - (k - curr.size()) + 1; i++) {
            curr.push_back(i);
            backtrack(i + 1);
            curr.pop_back();
        }
    };
    backtrack(1);
    return result;
}

// LC 216: Combination Sum III (k numbers sum to n, 1-9)
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> curr;
    function<void(int, int)> backtrack = [&](int start, int remaining) {
        if ((int)curr.size() == k && remaining == 0) { result.push_back(curr); return; }
        if ((int)curr.size() >= k || remaining < 0) return;
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(i + 1, remaining - i);
            curr.pop_back();
        }
    };
    backtrack(1, n);
    return result;
}

int main() {
    auto c = combine(4, 2);
    cout << "C(4,2): " << c.size() << " combinations\n";
    return 0;
}
