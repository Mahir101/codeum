// LC 282: Expression Add Operators | LC 679: 24 Game
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// LC 282: Expression Add Operators
vector<string> addOperators(string num, int target) {
    vector<string> result;
    function<void(int, long, long, string)> backtrack = [&](int idx, long prev, long curr, string expr) {
        if (idx == (int)num.size()) { if (curr == target) result.push_back(expr); return; }
        for (int i = idx; i < (int)num.size(); i++) {
            if (i > idx && num[idx] == '0') break;  // No leading zeros
            string s = num.substr(idx, i - idx + 1);
            long val = stol(s);
            if (idx == 0) backtrack(i + 1, val, val, s);
            else {
                backtrack(i + 1, val, curr + val, expr + "+" + s);
                backtrack(i + 1, -val, curr - val, expr + "-" + s);
                backtrack(i + 1, prev * val, curr - prev + prev * val, expr + "*" + s);
            }
        }
    };
    backtrack(0, 0, 0, "");
    return result;
}

// LC 679: 24 Game
bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());
    function<bool(vector<double>&)> solve = [&](vector<double>& nums) -> bool {
        if (nums.size() == 1) return abs(nums[0] - 24) < 1e-6;
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = 0; j < (int)nums.size(); j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < (int)nums.size(); k++) if (k != i && k != j) next.push_back(nums[k]);
                for (int op = 0; op < 4; op++) {
                    if (op < 2 && i > j) continue;  // Skip duplicate for + and *
                    double val;
                    if (op == 0) val = nums[i] + nums[j];
                    else if (op == 1) val = nums[i] * nums[j];
                    else if (op == 2) val = nums[i] - nums[j];
                    else { if (nums[j] == 0) continue; val = nums[i] / nums[j]; }
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    };
    return solve(nums);
}

int main() {
    auto exprs = addOperators("123", 6);
    cout << "Expressions for 123->6: " << exprs.size() << endl;
    return 0;
}
