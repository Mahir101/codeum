// LC 131: Palindrome Partitioning | Pattern: Backtrack Partition
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
    
    void backtrack(string& s, int start, vector<string>& curr, vector<vector<string>>& result) {
        if (start == (int)s.size()) { result.push_back(curr); return; }
        for (int end = start; end < (int)s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(s, 0, curr, result);
        return result;
    }
};

int main() {
    Solution sol;
    auto parts = sol.partition("aab");
    cout << "Palindrome partitions of 'aab': " << parts.size() << endl;
    return 0;
}
