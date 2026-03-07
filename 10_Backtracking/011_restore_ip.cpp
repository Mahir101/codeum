// LC 93: Restore IP Addresses | LC 140: Word Break II
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// LC 93: Restore IP Addresses
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    function<void(int, int, string)> backtrack = [&](int start, int parts, string curr) {
        if (parts == 4 && start == (int)s.size()) { result.push_back(curr.substr(1)); return; }
        if (parts == 4 || start == (int)s.size()) return;
        for (int len = 1; len <= 3 && start + len <= (int)s.size(); len++) {
            string part = s.substr(start, len);
            if ((len > 1 && part[0] == '0') || stoi(part) > 255) continue;
            backtrack(start + len, parts + 1, curr + "." + part);
        }
    };
    backtrack(0, 0, "");
    return result;
}

// LC 140: Word Break II
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<string> result;
    function<void(int, string)> backtrack = [&](int start, string curr) {
        if (start == (int)s.size()) { result.push_back(curr.substr(1)); return; }
        for (int end = start + 1; end <= (int)s.size(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) backtrack(end, curr + " " + word);
        }
    };
    backtrack(0, "");
    return result;
}

int main() {
    string s = "25525511135";
    auto ips = restoreIpAddresses(s);
    cout << "IP addresses: " << ips.size() << endl;
    return 0;
}
