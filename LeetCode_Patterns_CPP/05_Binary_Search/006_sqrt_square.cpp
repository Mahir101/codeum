// LC 69: Sqrt(x) | LC 367: Valid Perfect Square | LC 374: Guess Number
#include <iostream>
using namespace std;

// LC 69: sqrt using binary search
int mySqrt(int x) {
    if (x < 2) return x;
    long lo = 0, hi = x;
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (mid * mid == x) return mid;
        if (mid * mid < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return hi;
}

// LC 367: Valid Perfect Square
bool isPerfectSquare(int num) {
    long lo = 1, hi = num;
    while (lo <= hi) {
        long mid = lo + (hi - lo) / 2;
        if (mid * mid == num) return true;
        if (mid * mid < num) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

// LC 278: First Bad Version
// int firstBadVersion(int n) {
//     int lo = 1, hi = n;
//     while (lo < hi) {
//         int mid = lo + (hi - lo) / 2;
//         if (isBadVersion(mid)) hi = mid;
//         else lo = mid + 1;
//     }
//     return lo;
// }

int main() {
    cout << "sqrt(8): " << mySqrt(8) << endl;
    cout << "Is 16 perfect square: " << isPerfectSquare(16) << endl;
    return 0;
}
