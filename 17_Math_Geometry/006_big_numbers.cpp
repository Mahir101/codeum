// LC 66: Plus One | LC 43: Multiply Strings | LC 2: Add Two Numbers
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LC 66: Plus One
vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) { digits[i]++; return digits; }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

// LC 43: Multiply Strings
string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    vector<int> result(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    string str;
    for (int d : result) if (!(str.empty() && d == 0)) str += ('0' + d);
    return str.empty() ? "0" : str;
}

int main() {
    vector<int> digits = {1, 2, 9};
    auto result = plusOne(digits);
    cout << "Plus one: "; for (int d : result) cout << d; cout << endl;
    cout << "123 * 456 = " << multiply("123", "456") << endl;
    return 0;
}
