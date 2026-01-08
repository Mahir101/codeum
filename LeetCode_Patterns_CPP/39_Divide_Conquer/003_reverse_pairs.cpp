// LC 493: Reverse Pairs | LC 327: Count of Range Sum (with BIT/Merge Sort)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 493: Reverse Pairs (nums[i] > 2 * nums[j] where i < j)
class Solution493 {
    int count = 0;
    
    void mergeSort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);
        
        // Count reverse pairs
        int j = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (j <= hi && (long)nums[i] > 2L * nums[j]) j++;
            count += j - mid - 1;
        }
        
        // Merge
        vector<int> merged;
        int i = lo; j = mid + 1;
        while (i <= mid && j <= hi) {
            if (nums[i] <= nums[j]) merged.push_back(nums[i++]);
            else merged.push_back(nums[j++]);
        }
        while (i <= mid) merged.push_back(nums[i++]);
        while (j <= hi) merged.push_back(nums[j++]);
        for (int k = lo; k <= hi; k++) nums[k] = merged[k - lo];
    }
    
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};

// LC 327: Count of Range Sum
class Solution327 {
    int count = 0;
    int lower, upper;
    
    void mergeSort(vector<long>& sums, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(sums, lo, mid);
        mergeSort(sums, mid + 1, hi);
        
        int j = mid + 1, k = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (j <= hi && sums[j] - sums[i] < lower) j++;
            while (k <= hi && sums[k] - sums[i] <= upper) k++;
            count += k - j;
        }
        
        inplace_merge(sums.begin() + lo, sums.begin() + mid + 1, sums.begin() + hi + 1);
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower; this->upper = upper;
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + nums[i];
        mergeSort(sums, 0, n);
        return count;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    Solution493 sol;
    cout << "Reverse pairs: " << sol.reversePairs(nums) << endl;
    return 0;
}
