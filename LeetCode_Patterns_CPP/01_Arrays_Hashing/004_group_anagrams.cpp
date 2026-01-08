// LC 49: Group Anagrams
// Pattern: Hash Map with Custom Key
// Time: O(n * k log k) or O(n * k) | Space: O(n * k)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Approach 1: Sort as key
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [k, v] : groups) {
        result.push_back(v);
    }
    return result;
}

// Approach 2: Count array as key (O(n * k))
string getCountKey(const string& s) {
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    string key;
    for (int i = 0; i < 26; i++) {
        key += "#" + to_string(count[i]);
    }
    return key;
}

vector<vector<string>> groupAnagramsOptimal(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (const string& s : strs) {
        groups[getCountKey(s)].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [k, v] : groups) result.push_back(v);
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto groups = groupAnagrams(strs);
    cout << "Group Anagrams - " << groups.size() << " groups" << endl;
    return 0;
}
