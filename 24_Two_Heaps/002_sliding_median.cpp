// LC 480: Sliding Window Median
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> lo, hi;  // lo: left half (max), hi: right half (min)
    vector<double> result;
    
    for (int i = 0; i < (int)nums.size(); i++) {
        // Add new element
        if (lo.empty() || nums[i] <= *lo.rbegin()) lo.insert(nums[i]);
        else hi.insert(nums[i]);
        
        // Remove outgoing element
        if (i >= k) {
            int out = nums[i - k];
            if (lo.count(out)) lo.erase(lo.find(out));
            else hi.erase(hi.find(out));
        }
        
        // Rebalance
        while (lo.size() > hi.size() + 1) { hi.insert(*lo.rbegin()); lo.erase(prev(lo.end())); }
        while (hi.size() > lo.size()) { lo.insert(*hi.begin()); hi.erase(hi.begin()); }
        
        if (i >= k - 1) {
            result.push_back(k % 2 ? *lo.rbegin() : ((double)*lo.rbegin() + *hi.begin()) / 2);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto result = medianSlidingWindow(nums, 3);
    cout << "Sliding medians: "; for (double d : result) cout << d << " "; cout << endl;
    return 0;
}
