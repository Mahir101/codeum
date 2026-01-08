// LC 767: Reorganize String | LC 358: Rearrange String k Distance Apart
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// LC 767: Reorganize String (no adjacent same)
string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto& [c, f] : freq) {
        if (f > (s.size() + 1) / 2) return "";
        pq.push({f, c});
    }
    string result;
    while (pq.size() >= 2) {
        auto [f1, c1] = pq.top(); pq.pop();
        auto [f2, c2] = pq.top(); pq.pop();
        result += c1; result += c2;
        if (--f1 > 0) pq.push({f1, c1});
        if (--f2 > 0) pq.push({f2, c2});
    }
    if (!pq.empty()) result += pq.top().second;
    return result;
}

// LC 1054: Distant Barcodes (same as reorganize)
vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> freq;
    for (int b : barcodes) freq[b]++;
    priority_queue<pair<int, int>> pq;
    for (auto& [b, f] : freq) pq.push({f, b});
    vector<int> result;
    while (!pq.empty()) {
        auto [f1, b1] = pq.top(); pq.pop();
        if (result.empty() || result.back() != b1) {
            result.push_back(b1);
            if (--f1 > 0) pq.push({f1, b1});
        } else {
            auto [f2, b2] = pq.top(); pq.pop();
            result.push_back(b2);
            if (--f2 > 0) pq.push({f2, b2});
            pq.push({f1, b1});
        }
    }
    return result;
}

int main() {
    cout << "Reorganize 'aab': " << reorganizeString("aab") << endl;
    return 0;
}
