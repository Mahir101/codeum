// LC 17: Letter Combinations | LC 320: Generalized Abbreviations
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 17: Letter Combinations of Phone Number
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};
    
    for (char d : digits) {
        vector<string> next;
        for (auto& curr : result) {
            for (char c : mapping[d - '0']) {
                next.push_back(curr + c);
            }
        }
        result = next;
    }
    return result;
}

// LC 320: Generalized Abbreviations
vector<string> generateAbbreviations(string word) {
    vector<string> result;
    function<void(int, string, int)> backtrack = [&](int idx, string curr, int count) {
        if (idx == (int)word.size()) {
            result.push_back(count > 0 ? curr + to_string(count) : curr);
            return;
        }
        // Abbreviate
        backtrack(idx + 1, curr, count + 1);
        // Keep
        backtrack(idx + 1, curr + (count > 0 ? to_string(count) : "") + word[idx], 0);
    };
    backtrack(0, "", 0);
    return result;
}

// Generate all substrings/subsets
void generateAllSubsets(string& s, int idx, string curr, vector<string>& result) {
    result.push_back(curr);
    for (int i = idx; i < (int)s.size(); i++) {
        generateAllSubsets(s, i + 1, curr + s[i], result);
    }
}

int main() {
    auto combs = letterCombinations("23");
    cout << "Letter combinations: " << combs.size() << endl;
    return 0;
}
