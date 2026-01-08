// Segment Tree Pattern
// LC 307: Range Sum Query - Mutable | LC 315: Count Smaller After Self
// Range Min/Max Query | Lazy Propagation
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree, lazy;
    int n;
    
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) { tree[node] = nums[start]; return; }
        int mid = (start + end) / 2;
        build(nums, 2*node, start, mid);
        build(nums, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }
    
public:
    SegmentTree(vector<int>& nums) : n(nums.size()), tree(4 * n), lazy(4 * n, 0) {
        if (n > 0) build(nums, 1, 0, n - 1);
    }
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

// LC 307: Range Sum Query - Mutable
class NumArray {
    SegmentTree* st;
public:
    NumArray(vector<int>& nums) { st = new SegmentTree(nums); }
    void update(int index, int val) { st->update(index, val); }
    int sumRange(int left, int right) { return st->query(left, right); }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray na(nums);
    cout << "Sum [0,2]: " << na.sumRange(0, 2) << endl;
    na.update(1, 2);
    cout << "Sum [0,2] after update: " << na.sumRange(0, 2) << endl;
    return 0;
}
