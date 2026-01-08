// LC 432: All O(1) Data Structure | LC 1348: Tweet Counts
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

// LC 432: All O(1) Data Structure (getMaxKey, getMinKey, inc, dec)
class AllOne {
    struct Bucket { int count; set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> keyToBucket;
    
public:
    void inc(string key) {
        if (!keyToBucket.count(key)) {
            if (buckets.empty() || buckets.front().count != 1)
                buckets.push_front({1, {}});
            buckets.front().keys.insert(key);
            keyToBucket[key] = buckets.begin();
        } else {
            auto curr = keyToBucket[key];
            auto next = std::next(curr);
            if (next == buckets.end() || next->count != curr->count + 1)
                next = buckets.insert(next, {curr->count + 1, {}});
            next->keys.insert(key);
            curr->keys.erase(key);
            if (curr->keys.empty()) buckets.erase(curr);
            keyToBucket[key] = next;
        }
    }
    
    void dec(string key) {
        auto curr = keyToBucket[key];
        if (curr->count == 1) {
            curr->keys.erase(key);
            if (curr->keys.empty()) buckets.erase(curr);
            keyToBucket.erase(key);
        } else {
            auto prev = (curr == buckets.begin()) ? buckets.end() : std::prev(curr);
            if (prev == buckets.end() || prev->count != curr->count - 1)
                prev = buckets.insert(curr, {curr->count - 1, {}});
            prev->keys.insert(key);
            curr->keys.erase(key);
            if (curr->keys.empty()) buckets.erase(curr);
            keyToBucket[key] = prev;
        }
    }
    
    string getMaxKey() { return buckets.empty() ? "" : *buckets.back().keys.begin(); }
    string getMinKey() { return buckets.empty() ? "" : *buckets.front().keys.begin(); }
};

int main() {
    AllOne ao;
    ao.inc("hello"); ao.inc("hello");
    cout << "Max: " << ao.getMaxKey() << ", Min: " << ao.getMinKey() << endl;
    return 0;
}
