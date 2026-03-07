// Inversion Count with BIT | LC 493: Reverse Pairs
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BIT {
    vector<int> tree;
public:
    BIT(int n) : tree(n + 1, 0) {}
    void update(int i) { for (; i < (int)tree.size(); i += i & (-i)) tree[i]++; }
    int query(int i) { int sum = 0; for (; i > 0; i -= i & (-i)) sum += tree[i]; return sum; }
};

// Count inversions (i < j but arr[i] > arr[j])
long long countInversions(vector<int>& arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    int n = sorted.size();
    BIT bit(n);
    long long inversions = 0;
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        int idx = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
        inversions += bit.query(idx - 1);
        bit.update(idx);
    }
    return inversions;
}

// Range inversion queries with offline processing
class RangeInversions {
    vector<int> arr;
    int n;
    
public:
    RangeInversions(vector<int>& arr) : arr(arr), n(arr.size()) {}
    
    long long countInRange(int l, int r) {
        vector<int> sub(arr.begin() + l, arr.begin() + r + 1);
        return countInversions(sub);
    }
};

int main() {
    vector<int> arr = {8, 4, 2, 1};
    cout << "Inversions: " << countInversions(arr) << endl;
    return 0;
}
