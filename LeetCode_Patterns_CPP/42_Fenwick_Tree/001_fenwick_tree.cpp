// Fenwick Tree (Binary Indexed Tree) Pattern
// LC 307: Range Sum Query | LC 315: Count Smaller After Self
// Prefix Sum with Updates in O(log n)
#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;
public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    
    void update(int i, int delta) {
        for (++i; i <= n; i += i & (-i)) tree[i] += delta;
    }
    
    int query(int i) {  // Sum [0, i]
        int sum = 0;
        for (++i; i > 0; i -= i & (-i)) sum += tree[i];
        return sum;
    }
    
    int rangeQuery(int l, int r) { return query(r) - (l > 0 ? query(l - 1) : 0); }
};

// LC 307: Range Sum Query - Mutable (using BIT)
class NumArrayBIT {
    FenwickTree bit;
    vector<int> nums;
public:
    NumArrayBIT(vector<int>& nums) : bit(nums.size()), nums(nums) {
        for (int i = 0; i < (int)nums.size(); i++) bit.update(i, nums[i]);
    }
    void update(int index, int val) {
        bit.update(index, val - nums[index]);
        nums[index] = val;
    }
    int sumRange(int left, int right) { return bit.rangeQuery(left, right); }
};

// 2D Fenwick Tree
class FenwickTree2D {
    vector<vector<int>> tree;
    int m, n;
public:
    FenwickTree2D(int m, int n) : m(m), n(n), tree(m + 1, vector<int>(n + 1, 0)) {}
    
    void update(int r, int c, int delta) {
        for (int i = r + 1; i <= m; i += i & (-i))
            for (int j = c + 1; j <= n; j += j & (-j))
                tree[i][j] += delta;
    }
    
    int query(int r, int c) {
        int sum = 0;
        for (int i = r + 1; i > 0; i -= i & (-i))
            for (int j = c + 1; j > 0; j -= j & (-j))
                sum += tree[i][j];
        return sum;
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArrayBIT na(nums);
    cout << "Sum [0,2]: " << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << "Sum [0,2] after update: " << na.sumRange(0, 2) << endl;
    return 0;
}
