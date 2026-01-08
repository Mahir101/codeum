// LC 70: Climbing Stairs | Pattern: Fibonacci DP
// Time: O(n) | Space: O(1)
// Recognition: "How many ways to reach step n taking 1 or 2 steps"
#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    cout << "Climb 5 stairs: " << climbStairs(5) << " ways\n";
    return 0;
}
