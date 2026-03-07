// LC 318: Maximum Product of Word Lengths (no common letters)
// LC 201: Bitwise AND of Numbers Range
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LC 318: Max Product (no common letters)
int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++)
        for (char c : words[i]) masks[i] |= (1 << (c - 'a'));
    
    int maxProd = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((masks[i] & masks[j]) == 0)
                maxProd = max(maxProd, (int)(words[i].size() * words[j].size()));
    return maxProd;
}

// LC 201: Bitwise AND of Range [left, right]
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left != right) { left >>= 1; right >>= 1; shift++; }
    return left << shift;
}

int main() {
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << "Max product: " << maxProduct(words) << endl;
    cout << "AND [5,7]: " << rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
