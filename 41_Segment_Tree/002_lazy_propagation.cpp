// Segment Tree with Lazy Propagation (Range Updates)
#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
    vector<long long> tree, lazy;
    int n;
    
    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void updateRange(int node, int start, int end, int l, int r, long long val) {
        pushDown(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            pushDown(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    long long queryRange(int node, int start, int end, int l, int r) {
        pushDown(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return queryRange(2*node, start, mid, l, r) + queryRange(2*node+1, mid+1, end, l, r);
    }
    
public:
    LazySegmentTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}
    void updateRange(int l, int r, long long val) { updateRange(1, 0, n - 1, l, r, val); }
    long long queryRange(int l, int r) { return queryRange(1, 0, n - 1, l, r); }
};

int main() {
    LazySegmentTree st(10);
    st.updateRange(0, 5, 10);
    st.updateRange(3, 8, 5);
    cout << "Sum [0,9]: " << st.queryRange(0, 9) << endl;
    cout << "Sum [3,5]: " << st.queryRange(3, 5) << endl;
    return 0;
}
