// LC 658: Find K Closest Elements | LC 1060: Missing Element in Sorted Array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 658: Find K Closest Elements
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size() - k;
    while (left < right) {
        int mid = (left + right) / 2;
        if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;
        else right = mid;
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}

// LC 1060: Missing Element in Sorted Array (kth missing)
int missingElement(vector<int>& nums, int k) {
    int n = nums.size();
    auto missing = [&](int idx) { return nums[idx] - nums[0] - idx; };
    if (k > missing(n - 1)) return nums[n - 1] + k - missing(n - 1);
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (missing(mid) < k) lo = mid + 1;
        else hi = mid;
    }
    return nums[lo - 1] + k - missing(lo - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    auto closest = findClosestElements(arr, 4, 3);
    cout << "K closest: "; for (int x : closest) cout << x << " "; cout << endl;
    return 0;
}
