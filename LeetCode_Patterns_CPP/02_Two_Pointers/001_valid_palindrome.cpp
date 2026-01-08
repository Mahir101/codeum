// LC 125: Valid Palindrome
// Pattern: Two Pointers (Converging)
// Time: O(n) | Space: O(1)
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

int main() {
    cout << "\"A man, a plan, a canal: Panama\": " << (isPalindrome("A man, a plan, a canal: Panama") ? "Yes" : "No") << endl;
    cout << "\"race a car\": " << (isPalindrome("race a car") ? "Yes" : "No") << endl;
    return 0;
}
