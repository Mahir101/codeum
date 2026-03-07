// LC 215: Kth Largest Element | Pattern: Min Heap / QuickSelect
// Time: O(n log k) heap, O(n) avg quickselect | Space: O(k)
// Recognition: "Find kth largest/smallest element"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Heap approach
int findKthLargestHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// QuickSelect approach
int quickSelect(vector<int>& nums, int l, int r, int k) {
    int pivot = nums[r], p = l;
    for (int i = l; i < r; i++) {
        if (nums[i] <= pivot) swap(nums[i], nums[p++]);
    }
    swap(nums[p], nums[r]);
    if (p == k) return nums[p];
    return p < k ? quickSelect(nums, p + 1, r, k) : quickSelect(nums, l, p - 1, k);
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << "2nd largest: " << findKthLargestHeap(nums, 2) << endl;
    return 0;
}
