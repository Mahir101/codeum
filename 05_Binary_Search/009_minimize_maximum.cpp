// LC 1011: Capacity to Ship | LC 875: Koko Eating Bananas
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// LC 1011: Capacity To Ship Packages Within D Days
int shipWithinDays(vector<int>& weights, int days) {
    int lo = *max_element(weights.begin(), weights.end());
    int hi = accumulate(weights.begin(), weights.end(), 0);
    
    auto canShip = [&](int capacity) {
        int required = 1, load = 0;
        for (int w : weights) {
            if (load + w > capacity) { required++; load = 0; }
            load += w;
        }
        return required <= days;
    };
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (canShip(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// LC 875: Koko Eating Bananas
int minEatingSpeed(vector<int>& piles, int h) {
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    
    auto canFinish = [&](int k) -> bool {
        long hours = 0;
        for (int p : piles) hours += (p + k - 1) / k;
        return hours <= h;
    };
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (canFinish(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// LC 410: Split Array Largest Sum
int splitArray(vector<int>& nums, int k) {
    int lo = *max_element(nums.begin(), nums.end());
    int hi = accumulate(nums.begin(), nums.end(), 0);
    
    auto canSplit = [&](int maxSum) {
        int count = 1, currSum = 0;
        for (int n : nums) {
            if (currSum + n > maxSum) { count++; currSum = 0; }
            currSum += n;
        }
        return count <= k;
    };
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (canSplit(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << "Ship in 5 days: " << shipWithinDays(weights, 5) << endl;
    return 0;
}
