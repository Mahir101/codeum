// LC 71: Simplify Path
// Pattern: Stack for Path Processing
// Time: O(n) | Space: O(n)
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    vector<string> stk;
    stringstream ss(path);
    string token;
    
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") continue;
        if (token == "..") {
            if (!stk.empty()) stk.pop_back();
        } else {
            stk.push_back(token);
        }
    }
    
    string result;
    for (const string& s : stk) result += "/" + s;
    return result.empty() ? "/" : result;
}

int main() {
    cout << "/home/: " << simplifyPath("/home/") << endl;
    cout << "/../: " << simplifyPath("/../") << endl;
    cout << "/home//foo/: " << simplifyPath("/home//foo/") << endl;
    return 0;
}
