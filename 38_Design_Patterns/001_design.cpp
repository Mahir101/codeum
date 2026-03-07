// Design Pattern - System Design Data Structures
// LC 146: LRU Cache | LC 460: LFU Cache | LC 380: RandomizedSet
// LC 706: Design HashMap | LC 707: Design LinkedList
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
using namespace std;

// LC 380: Insert Delete GetRandom O(1)
class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> valToIdx;
public:
    bool insert(int val) {
        if (valToIdx.count(val)) return false;
        valToIdx[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    bool remove(int val) {
        if (!valToIdx.count(val)) return false;
        int idx = valToIdx[val];
        nums[idx] = nums.back();
        valToIdx[nums[idx]] = idx;
        nums.pop_back();
        valToIdx.erase(val);
        return true;
    }
    int getRandom() { return nums[rand() % nums.size()]; }
};

// LC 706: Design HashMap (separate chaining)
class MyHashMap {
    static const int SIZE = 10007;
    vector<list<pair<int, int>>> buckets;
    int hash(int key) { return key % SIZE; }
public:
    MyHashMap() : buckets(SIZE) {}
    void put(int key, int value) {
        int h = hash(key);
        for (auto& [k, v] : buckets[h]) { if (k == key) { v = value; return; } }
        buckets[h].push_back({key, value});
    }
    int get(int key) {
        int h = hash(key);
        for (auto& [k, v] : buckets[h]) if (k == key) return v;
        return -1;
    }
    void remove(int key) {
        int h = hash(key);
        buckets[h].remove_if([key](auto& p) { return p.first == key; });
    }
};

// LC 381: Insert Delete GetRandom O(1) - Duplicates allowed
class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> valToIndices;
public:
    bool insert(int val) {
        valToIndices[val].insert(nums.size());
        nums.push_back(val);
        return valToIndices[val].size() == 1;
    }
    bool remove(int val) {
        if (!valToIndices.count(val) || valToIndices[val].empty()) return false;
        int idx = *valToIndices[val].begin();
        valToIndices[val].erase(idx);
        int lastVal = nums.back();
        nums[idx] = lastVal;
        valToIndices[lastVal].insert(idx);
        valToIndices[lastVal].erase(nums.size() - 1);
        nums.pop_back();
        if (valToIndices[val].empty()) valToIndices.erase(val);
        return true;
    }
    int getRandom() { return nums[rand() % nums.size()]; }
};

int main() {
    RandomizedSet rs;
    rs.insert(1); rs.insert(2); rs.remove(1);
    cout << "Random: " << rs.getRandom() << endl;
    return 0;
}
