"""
Sliding Window - Minimum Window (Shortest Substring)
Template for problems like Minimum Window Substring
Time: O(n), Space: O(k)
"""

from collections import Counter

def min_window(s, t):
    """
    LeetCode 76: Minimum Window Substring (HARD)
    Find smallest window in s containing all characters of t.
    """
    if not s or not t:
        return ""
    
    # Count characters needed
    dict_t = Counter(t)
    required = len(dict_t)
    
    # Sliding window counters
    left, right = 0, 0
    formed = 0  # How many unique chars in window match required frequency
    window_counts = {}
    
    # Result (window length, left, right)
    ans = float('inf'), None, None
    
    while right < len(s):
        # Expand window
        char = s[right]
        window_counts[char] = window_counts.get(char, 0) + 1
        
        # Check if frequency matches
        if char in dict_t and window_counts[char] == dict_t[char]:
            formed += 1
        
        # Try to contract window while valid
        while left <= right and formed == required:
            char = s[left]
            
            # Update result if smaller window found
            if right - left + 1 < ans[0]:
                ans = (right - left + 1, left, right)
            
            # Remove from window
            window_counts[char] -= 1
            if char in dict_t and window_counts[char] < dict_t[char]:
                formed -= 1
            
            left += 1
        
        right += 1
    
    return "" if ans[0] == float('inf') else s[ans[1]:ans[2] + 1]


def min_size_subarray_sum(target, nums):
    """
    LeetCode 209: Minimum Size Subarray Sum
    Find minimal length subarray with sum >= target.
    """
    left = 0
    min_length = float('inf')
    current_sum = 0
    
    for right in range(len(nums)):
        current_sum += nums[right]
        
        # Shrink window while condition met
        while current_sum >= target:
            min_length = min(min_length, right - left + 1)
            current_sum -= nums[left]
            left += 1
    
    return 0 if min_length == float('inf') else min_length


def find_anagrams(s, p):
    """
    LeetCode 438: Find All Anagrams in a String
    Find all start indices of p's anagrams in s.
    """
    if len(s) < len(p):
        return []
    
    p_count = Counter(p)
    s_count = Counter(s[:len(p)])
    result = []
    
    if s_count == p_count:
        result.append(0)
    
    # Slide window
    for i in range(len(p), len(s)):
        # Add new character
        s_count[s[i]] += 1
        
        # Remove old character
        s_count[s[i - len(p)]] -= 1
        if s_count[s[i - len(p)]] == 0:
            del s_count[s[i - len(p)]]
        
        # Check if anagram
        if s_count == p_count:
            result.append(i - len(p) + 1)
    
    return result


# Test cases
if __name__ == "__main__":
    # Test minimum window substring
    assert min_window("ADOBECODEBANC", "ABC") == "BANC"
    assert min_window("a", "a") == "a"
    assert min_window("a", "aa") == ""
    print("✓ min_window")
    
    # Test minimum size subarray
    assert min_size_subarray_sum(7, [2,3,1,2,4,3]) == 2
    assert min_size_subarray_sum(4, [1,4,4]) == 1
    assert min_size_subarray_sum(11, [1,1,1,1,1,1,1,1]) == 0
    print("✓ min_size_subarray_sum")
    
    # Test find anagrams
    assert find_anagrams("cbaebabacd", "abc") == [0, 6]
    assert find_anagrams("abab", "ab") == [0, 1, 2]
    print("✓ find_anagrams")
    
    print("\n✅ All tests passed!")
