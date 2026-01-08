// LC 680: Valid Palindrome II
// Pattern: Two Pointers with Skip
// Time: O(n) | Space: O(1)
#include <iostream>
#include <string>
using namespace std;

bool isPalindromeRange(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return isPalindromeRange(s, left + 1, right) || 
                   isPalindromeRange(s, left, right - 1);
        }
        left++; right--;
    }
    return true;
}

int main() {
    cout << "\"aba\": " << (validPalindrome("aba") ? "Yes" : "No") << endl;
    cout << "\"abca\": " << (validPalindrome("abca") ? "Yes" : "No") << endl;
    cout << "\"abc\": " << (validPalindrome("abc") ? "Yes" : "No") << endl;
    return 0;
}
