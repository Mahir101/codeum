// Counting Pattern (HashMap for frequency counting)
// LC 169: Majority Element | LC 347: Top K Frequent | LC 49: Group Anagrams
// LC 242: Valid Anagram | LC 1: Two Sum | LC 128: Longest Consecutive
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// LC 169: Majority Element (Boyer-Moore)
int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

// LC 347: Top K Frequent Elements (Bucket Sort)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto& [num, f] : freq) buckets[f].push_back(num);
    vector<int> result;
    for (int i = buckets.size() - 1; i >= 0 && (int)result.size() < k; i--)
        for (int n : buckets[i]) { result.push_back(n); if ((int)result.size() == k) break; }
    return result;
}

// LC 128: Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;
    for (int num : numSet) {
        if (!numSet.count(num - 1)) {  // Start of sequence
            int len = 1;
            while (numSet.count(num + len)) len++;
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

// LC 560: Subarray Sum (with counting)
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount; prefixCount[0] = 1;
    int sum = 0, count = 0;
    for (int n : nums) { sum += n; count += prefixCount[sum - k]; prefixCount[sum]++; }
    return count;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive: " << longestConsecutive(nums) << endl;
    return 0;
}
