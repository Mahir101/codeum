// LC 402: Remove K Digits
// Pattern: Monotonic Stack (Greedy)
// Time: O(n) | Space: O(n)
#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    string result;
    
    for (char c : num) {
        while (!result.empty() && result.back() > c && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }
    
    // Remove remaining from end
    while (k-- > 0 && !result.empty()) result.pop_back();
    
    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    return start == string::npos ? "0" : result.substr(start);
}

int main() {
    cout << "1432219, k=3: " << removeKdigits("1432219", 3) << endl;
    cout << "10200, k=1: " << removeKdigits("10200", 1) << endl;
    return 0;
}
