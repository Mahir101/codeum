// LC 76: Minimum Window Substring | LC 632: Smallest Range (dual pointer)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 76: Minimum Window Substring (classic sliding window)
string minWindow(string s, string t) {
    unordered_map<char, int> need, have;
    for (char c : t) need[c]++;
    int left = 0, minLen = INT_MAX, minStart = 0, matches = 0;
    
    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];
        have[c]++;
        if (need.count(c) && have[c] == need[c]) matches++;
        
        while (matches == (int)need.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            char leftChar = s[left++];
            if (need.count(leftChar) && have[leftChar] == need[leftChar]) matches--;
            have[leftChar]--;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

// LC 438: Find All Anagrams in a String
vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) return {};
    vector<int> result, pCount(26, 0), sCount(26, 0);
    for (char c : p) pCount[c - 'a']++;
    for (int i = 0; i < (int)s.size(); i++) {
        sCount[s[i] - 'a']++;
        if (i >= (int)p.size()) sCount[s[i - p.size()] - 'a']--;
        if (sCount == pCount) result.push_back(i - p.size() + 1);
    }
    return result;
}

int main() {
    cout << "Min window 'ADOBECODEBANC','ABC': " << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
