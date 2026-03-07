// LC 146: LRU Cache | Pattern: HashMap + Doubly Linked List
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;  // Dummy nodes
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        insertFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
            delete cache[key];
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insertFront(node);
        if ((int)cache.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1); cache.put(2, 2);
    cout << "Get 1: " << cache.get(1) << endl;
    cache.put(3, 3);
    cout << "Get 2 (evicted): " << cache.get(2) << endl;
    return 0;
}
