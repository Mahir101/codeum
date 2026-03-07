// LC 29: Divide Two Integers | LC 166: Fraction to Recurring Decimal
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// LC 29: Divide without *, /, %
int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    long dvd = labs(dividend), dvs = labs(divisor);
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    long result = 0;
    while (dvd >= dvs) {
        long temp = dvs, mult = 1;
        while (dvd >= (temp << 1)) { temp <<= 1; mult <<= 1; }
        dvd -= temp;
        result += mult;
    }
    return sign * result;
}

// LC 166: Fraction to Recurring Decimal
string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    string result;
    if ((numerator < 0) ^ (denominator < 0)) result += "-";
    long n = labs(numerator), d = labs(denominator);
    result += to_string(n / d);
    n %= d;
    if (n == 0) return result;
    result += ".";
    unordered_map<long, int> seen;
    while (n != 0) {
        if (seen.count(n)) {
            result.insert(seen[n], "(");
            result += ")";
            break;
        }
        seen[n] = result.size();
        n *= 10;
        result += to_string(n / d);
        n %= d;
    }
    return result;
}

int main() {
    cout << "10 / 3 = " << divide(10, 3) << endl;
    cout << "1/6 = " << fractionToDecimal(1, 6) << endl;
    return 0;
}
