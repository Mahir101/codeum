// LC 315: Count of Smaller Numbers After Self (using BIT)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1, 0) {}
    void update(int i) { for (; i < (int)tree.size(); i += i & (-i)) tree[i]++; }
    int query(int i) { int sum = 0; for (; i > 0; i -= i & (-i)) sum += tree[i]; return sum; }
};

vector<int> countSmaller(vector<int>& nums) {
    // Coordinate compression
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    auto getIndex = [&](int x) {
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
    };
    
    int n = nums.size();
    FenwickTree bit(sorted.size());
    vector<int> result(n);
    
    for (int i = n - 1; i >= 0; i--) {
        int idx = getIndex(nums[i]);
        result[i] = bit.query(idx - 1);
        bit.update(idx);
    }
    
    return result;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    auto result = countSmaller(nums);
    cout << "Count smaller: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
