// LC 204: Count Primes | LC 172: Trailing Zeroes | LC 231: Power of Two
#include <iostream>
#include <vector>
using namespace std;

// LC 204: Count Primes (Sieve of Eratosthenes)
int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) isPrime[j] = false;
        }
    }
    int count = 0;
    for (bool p : isPrime) if (p) count++;
    return count;
}

// LC 172: Factorial Trailing Zeroes (count 5s)
int trailingZeroes(int n) {
    int count = 0;
    while (n >= 5) { n /= 5; count += n; }
    return count;
}

// LC 231: Power of Two
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }

// LC 326: Power of Three
bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }

// LC 12: Integer to Roman
string intToRoman(int num) {
    vector<pair<int, string>> vals = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
        {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
    string result;
    for (auto& [val, sym] : vals) while (num >= val) { result += sym; num -= val; }
    return result;
}

int main() {
    cout << "Primes < 30: " << countPrimes(30) << endl;
    cout << "Trailing zeros 100!: " << trailingZeroes(100) << endl;
    return 0;
}
