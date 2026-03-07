// LC 3: Longest Substring No Repeat | LC 424: Longest Repeating with K Changes
// LC 567: Permutation in String | LC 438: Find All Anagrams
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// LC 424: Longest Repeating Character Replacement
int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int left = 0, maxCount = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        count[s[right] - 'A']++;
        maxCount = max(maxCount, count[s[right] - 'A']);
        while (right - left + 1 - maxCount > k) {
            count[s[left] - 'A']--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// LC 438: Find All Anagrams
vector<int> findAnagrams(string s, string p) {
    vector<int> result, pCount(26, 0), sCount(26, 0);
    if (s.size() < p.size()) return result;
    for (char c : p) pCount[c - 'a']++;
    for (int i = 0; i < (int)s.size(); i++) {
        sCount[s[i] - 'a']++;
        if (i >= (int)p.size()) sCount[s[i - p.size()] - 'a']--;
        if (sCount == pCount) result.push_back(i - p.size() + 1);
    }
    return result;
}

int main() {
    cout << "Character replacement (AABABBA, k=1): " << characterReplacement("AABABBA", 1) << endl;
    return 0;
}
