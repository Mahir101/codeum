// LC 271: Encode and Decode Strings
// Pattern: Length Prefix Encoding
// Time: O(n) | Space: O(1) excluding output
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // Encodes a list of strings to a single string
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }
    
    // Decodes a single string to a list of strings
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < (int)s.size()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return result;
    }
};

int main() {
    Codec codec;
    vector<string> strs = {"Hello", "World", "Foo#Bar"};
    string encoded = codec.encode(strs);
    cout << "Encoded: " << encoded << endl;
    vector<string> decoded = codec.decode(encoded);
    cout << "Decoded: ";
    for (const string& s : decoded) cout << "[" << s << "] ";
    cout << endl;
    return 0;
}
