// Range Minimum Query with Segment Tree
// LC 2407: Longest Increasing Subsequence II
#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeMax {
    vector<int> tree;
    int n;
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) { tree[node] = max(tree[node], val); return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
    }
    
public:
    SegmentTreeMax(int n) : n(n), tree(4 * n, 0) {}
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
    int query(int l, int r) { return l > r ? 0 : query(1, 0, n - 1, l, r); }
};

// LC 2407: Longest Increasing Subsequence II
int lengthOfLIS(vector<int>& nums, int k) {
    int maxVal = *max_element(nums.begin(), nums.end());
    SegmentTreeMax st(maxVal + 1);
    int result = 0;
    
    for (int num : nums) {
        int maxLen = st.query(max(0, num - k), num - 1);
        st.update(num, maxLen + 1);
        result = max(result, maxLen + 1);
    }
    return result;
}

int main() {
    vector<int> nums = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    cout << "LIS with k=3: " << lengthOfLIS(nums, 3) << endl;
    return 0;
}
