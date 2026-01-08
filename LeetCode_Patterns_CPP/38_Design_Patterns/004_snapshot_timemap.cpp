// LC 1146: Snapshot Array | LC 981: Time Based Key-Value Store
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// LC 1146: Snapshot Array
class SnapshotArray {
    vector<map<int, int>> history;  // For each index, map snap_id -> value
    int snapId = 0;
public:
    SnapshotArray(int length) : history(length) {}
    void set(int index, int val) { history[index][snapId] = val; }
    int snap() { return snapId++; }
    int get(int index, int snap_id) {
        auto it = history[index].upper_bound(snap_id);
        return it == history[index].begin() ? 0 : prev(it)->second;
    }
};

// LC 981: Time Based Key-Value Store
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        auto& vec = store[key];
        int lo = 0, hi = vec.size() - 1, result = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (vec[mid].first <= timestamp) { result = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return result >= 0 ? vec[result].second : "";
    }
};

int main() {
    SnapshotArray sa(3);
    sa.set(0, 5);
    cout << "Snap: " << sa.snap() << endl;
    sa.set(0, 6);
    cout << "Get(0, 0): " << sa.get(0, 0) << endl;
    return 0;
}
