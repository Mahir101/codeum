// LC 678: Valid Parenthesis String | LC 846: Hand of Straights
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// LC 678: Valid Parenthesis String with '*'
bool checkValidString(string s) {
    int low = 0, high = 0;
    for (char c : s) {
        low += (c == '(') ? 1 : -1;
        high += (c != ')') ? 1 : -1;
        if (high < 0) return false;
        low = max(low, 0);
    }
    return low == 0;
}

// LC 846: Hand of Straights (group into consecutive)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
    map<int, int> count;
    for (int card : hand) count[card]++;
    for (auto& [card, cnt] : count) {
        if (cnt > 0) {
            for (int i = 0; i < groupSize; i++) {
                if (count[card + i] < cnt) return false;
                count[card + i] -= cnt;
            }
        }
    }
    return true;
}

int main() {
    cout << "Valid '(*)': " << checkValidString("(*)") << endl;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << "Hand of straights (3): " << isNStraightHand(hand, 3) << endl;
    return 0;
}
