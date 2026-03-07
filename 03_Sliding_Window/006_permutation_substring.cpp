// LC 567: Permutation in String | LC 30: Substring with Concatenation
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// LC 567: Check if s2 contains permutation of s1
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> freq(26, 0);
    for (char c : s1) freq[c - 'a']++;
    int left = 0, matches = 0;
    for (int right = 0; right < (int)s2.size(); right++) {
        int idx = s2[right] - 'a';
        if (--freq[idx] >= 0) matches++;
        while (matches == (int)s1.size()) {
            if (right - left + 1 == (int)s1.size()) return true;
            int lIdx = s2[left++] - 'a';
            if (++freq[lIdx] > 0) matches--;
        }
    }
    return false;
}

// LC 30: Substring with Concatenation of All Words
vector<int> findSubstring(string s, vector<string>& words) {
    if (words.empty() || s.empty()) return {};
    int wordLen = words[0].size(), wordCount = words.size();
    int totalLen = wordLen * wordCount;
    unordered_map<string, int> wordFreq;
    for (auto& w : words) wordFreq[w]++;
    vector<int> result;
    for (int i = 0; i <= (int)s.size() - totalLen; i++) {
        unordered_map<string, int> seen;
        int j = 0;
        for (; j < wordCount; j++) {
            string word = s.substr(i + j * wordLen, wordLen);
            if (!wordFreq.count(word) || ++seen[word] > wordFreq[word]) break;
        }
        if (j == wordCount) result.push_back(i);
    }
    return result;
}

int main() {
    cout << "Permutation check 'ab' in 'eidbaooo': " << checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
