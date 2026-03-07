// LC 904: Fruit Into Baskets | LC 1004: Max Consecutive Ones III
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LC 904: Max fruits with 2 types (longest subarray with at most 2 distinct)
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> count;
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)fruits.size(); right++) {
        count[fruits[right]]++;
        while (count.size() > 2) {
            if (--count[fruits[left]] == 0) count.erase(fruits[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// LC 1004: Max Consecutive Ones with K flips
int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeros = 0, maxLen = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > k) {
            if (nums[left++] == 0) zeros--;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// LC 340: Longest Substring with At Most K Distinct
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> count;
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        count[s[right]]++;
        while ((int)count.size() > k) {
            if (--count[s[left]] == 0) count.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    cout << "Max ones (k=2): " << longestOnes(nums, 2) << endl;
    return 0;
}
