// LC 242: Valid Anagram
// Pattern: Frequency Count / Hash Map
// Time: O(n) | Space: O(1) - fixed alphabet
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (int i = 0; i < (int)s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int c : count) if (c != 0) return false;
    return true;
}

int main() {
    cout << "anagram, nagaram: " << (isAnagram("anagram", "nagaram") ? "Yes" : "No") << endl;
    cout << "rat, car: " << (isAnagram("rat", "car") ? "Yes" : "No") << endl;
    return 0;
}
