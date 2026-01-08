/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║  BINARY SEARCH ON ANSWER: Koko Eating Bananas                             ║
 * ║  LeetCode 875 | Difficulty: Medium                                        ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🎯 PATTERN RECOGNITION CUES                                             │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ ✓ "Minimum/maximum value such that X is achievable"                     │
 * │ ✓ Answer lies in a bounded range [min, max]                             │
 * │ ✓ Monotonic feasibility: if X works, all values > X also work          │
 * │ ✓ Checking feasibility is O(n) or better                                │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🧠 BRAIN TRAINING: Binary Search on Answer Template                     │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ 1. Define the search space [lo, hi] for the ANSWER                      │
 * │ 2. Write a feasibility function: canAchieve(mid)                        │
 * │ 3. Binary search to find minimum/maximum feasible answer                │
 * │                                                                         │
 * │ MINIMUM FEASIBLE:                                                       │
 * │   if (canAchieve(mid)) hi = mid;  // try smaller                        │
 * │   else lo = mid + 1;              // need larger                        │
 * │                                                                         │
 * │ MAXIMUM FEASIBLE:                                                       │
 * │   if (canAchieve(mid)) lo = mid;  // try larger                         │
 * │   else hi = mid - 1;              // need smaller                       │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * Time: O(n * log(max)) | Space: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // LC 875: Koko Eating Bananas
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFinish(piles, mid, h)) {
                hi = mid;  // Can finish at this speed, try slower
            } else {
                lo = mid + 1;  // Too slow, need faster
            }
        }
        
        return lo;
    }
    
    // LC 1011: Capacity To Ship Packages Within D Days
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShip(weights, mid, days)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    // LC 410: Split Array Largest Sum (minimize max sum)
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canSplit(nums, mid, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
private:
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;  // Ceiling division
        }
        return hours <= h;
    }
    
    bool canShip(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0, daysNeeded = 1;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                daysNeeded++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return daysNeeded <= days;
    }
    
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int count = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }
        return count <= k;
    }
};

/*
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 📚 SIMILAR PROBLEMS                                                     │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ LC 1283: Find Smallest Divisor                                          │
 * │ LC 1482: Minimum Days to Make m Bouquets                                │
 * │ LC 774: Minimize Max Distance to Gas Station                            │
 * │ LC 69: Sqrt(x) - binary search on answer                                │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

int main() {
    Solution sol;
    
    cout << "Pattern: BINARY SEARCH ON ANSWER\n";
    cout << "=================================\n\n";
    
    vector<int> piles = {3, 6, 7, 11};
    cout << "Koko Eating Bananas [3,6,7,11], h=8\n";
    cout << "Minimum speed: " << sol.minEatingSpeed(piles, 8) << "\n\n";
    
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Ship packages [1-10], days=5\n";
    cout << "Minimum capacity: " << sol.shipWithinDays(weights, 5) << "\n\n";
    
    vector<int> nums = {7, 2, 5, 10, 8};
    cout << "Split array [7,2,5,10,8], k=2\n";
    cout << "Minimum max sum: " << sol.splitArray(nums, 2) << "\n";
    
    return 0;
}
