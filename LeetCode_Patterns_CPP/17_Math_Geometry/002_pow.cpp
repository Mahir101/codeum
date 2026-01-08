// LC 50: Pow(x, n) | Pattern: Fast Exponentiation
// Time: O(log n) | Space: O(1)
#include <iostream>
using namespace std;

double myPow(double x, long n) {
    if (n < 0) { x = 1 / x; n = -n; }
    double result = 1;
    while (n > 0) {
        if (n & 1) result *= x;
        x *= x; n >>= 1;
    }
    return result;
}

int main() {
    cout << "2^10 = " << myPow(2, 10) << endl;
    cout << "2^-2 = " << myPow(2, -2) << endl;
    return 0;
}
