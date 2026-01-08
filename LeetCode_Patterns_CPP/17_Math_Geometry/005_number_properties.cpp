// LC 202: Happy Number | LC 263: Ugly Number | LC 9: Palindrome Number
#include <iostream>
#include <unordered_set>
using namespace std;

// LC 202: Happy Number (Floyd's cycle detection)
int getNext(int n) {
    int sum = 0;
    while (n > 0) { int d = n % 10; sum += d * d; n /= 10; }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = getNext(n);
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}

// LC 263: Ugly Number (only 2, 3, 5 as prime factors)
bool isUgly(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}

// LC 9: Palindrome Number (no string conversion)
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int rev = 0;
    while (x > rev) { rev = rev * 10 + x % 10; x /= 10; }
    return x == rev || x == rev / 10;
}

int main() {
    cout << "Is 19 happy: " << isHappy(19) << endl;
    cout << "Is 6 ugly: " << isUgly(6) << endl;
    cout << "Is 121 palindrome: " << isPalindrome(121) << endl;
    return 0;
}
