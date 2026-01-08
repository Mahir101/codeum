// LC 344: Reverse String
// Pattern: Two Pointers Swap
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

// LC 541: Reverse String II (every 2k chars, reverse first k)
string reverseStr(string s, int k) {
    for (int i = 0; i < (int)s.size(); i += 2 * k) {
        int left = i, right = min(i + k - 1, (int)s.size() - 1);
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    return s;
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    cout << "Reversed: ";
    for (char c : s) cout << c;
    cout << endl;
    return 0;
}
