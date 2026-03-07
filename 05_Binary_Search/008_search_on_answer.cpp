// LC 1889: Minimum Space Wasted From Packaging | LC 1300: Sum of Mutated Array Closest to Target
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// LC 1300: Sum of Mutated Array Closest to Target
int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + arr[i];
    
    int lo = 0, hi = *max_element(arr.begin(), arr.end());
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        auto it = upper_bound(arr.begin(), arr.end(), mid);
        int idx = it - arr.begin();
        long sum = prefix[idx] + (long)(n - idx) * mid;
        if (sum < target) lo = mid + 1;
        else hi = mid;
    }
    
    auto calcSum = [&](int val) {
        auto it = upper_bound(arr.begin(), arr.end(), val);
        int idx = it - arr.begin();
        return prefix[idx] + (long)(n - idx) * val;
    };
    
    long sum1 = calcSum(lo), sum2 = calcSum(lo - 1);
    return abs(sum1 - target) < abs(sum2 - target) ? lo : lo - 1;
}

// Binary search on answer template
int searchOnAnswer(vector<int>& arr, int target) {
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        // if condition(mid) satisfies target lo = mid + 1 else hi = mid
        if (mid < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    vector<int> arr = {4, 9, 3};
    cout << "Best value for target 10: " << findBestValue(arr, 10) << endl;
    return 0;
}
