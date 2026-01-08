// LC 4: Median of Two Sorted Arrays | Pattern: Binary Search on Partition
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    int m = nums1.size(), n = nums2.size();
    int lo = 0, hi = m;
    
    while (lo <= hi) {
        int i = (lo + hi) / 2;  // Partition in nums1
        int j = (m + n + 1) / 2 - i;  // Partition in nums2
        
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];
        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];
        
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0)
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            return max(maxLeft1, maxLeft2);
        }
        if (maxLeft1 > minRight2) hi = i - 1;
        else lo = i + 1;
    }
    return 0;
}

int main() {
    vector<int> nums1 = {1, 3}, nums2 = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
