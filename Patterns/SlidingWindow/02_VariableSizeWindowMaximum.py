"""
Sliding Window - Variable Size (Longest Substring)
Template for problems like Longest Substring Without Repeating Characters
Time: O(n), Space: O(k) where k is character set size
"""

def length_of_longest_substring(s):
    """
    LeetCode 3: Longest Substring Without Repeating Characters
    Find length of longest substring without repeating characters.
    """
    char_set = set()
    left = 0
    max_length = 0
    
    for right in range(len(s)):
        # Shrink window while duplicate exists
        while s[right] in char_set:
            char_set.remove(s[left])
            left += 1
        
        char_set.add(s[right])
        max_length = max(max_length, right - left + 1)
    
    return max_length


def character_replacement(s, k):
    """
    LeetCode 424: Longest Repeating Character Replacement
    Longest substring with same letter after replacing at most k characters.
    """
    from collections import Counter
    
    left = 0
    max_length = 0
    max_freq = 0
    char_count = Counter()
    
    for right in range(len(s)):
        char_count[s[right]] += 1
        max_freq = max(max_freq, char_count[s[right]])
        
        # If window size - max_freq > k, shrink window
        window_size = right - left + 1
        if window_size - max_freq > k:
            char_count[s[left]] -= 1
            left += 1
        
        max_length = max(max_length, right - left + 1)
    
    return max_length


def longest_subarray_with_at_most_k_distinct(s, k):
    """
    LeetCode 340: Longest Substring with At Most K Distinct Characters
    Find longest substring with at most k distinct characters.
    """
    from collections import defaultdict
    
    char_count = defaultdict(int)
    left = 0
    max_length = 0
    
    for right in range(len(s)):
        char_count[s[right]] += 1
        
        # Shrink while more than k distinct
        while len(char_count) > k:
            char_count[s[left]] -= 1
            if char_count[s[left]] == 0:
                del char_count[s[left]]
            left += 1
        
        max_length = max(max_length, right - left + 1)
    
    return max_length


# Test cases
if __name__ == "__main__":
    # Test longest substring
    assert length_of_longest_substring("abcabcbb") == 3
    assert length_of_longest_substring("bbbbb") == 1
    assert length_of_longest_substring("pwwkew") == 3
    print("✓ length_of_longest_substring")
    
    # Test character replacement
    assert character_replacement("ABAB", 2) == 4
    assert character_replacement("AABABBA", 1) == 4
    print("✓ character_replacement")
    
    # Test k distinct
    assert longest_subarray_with_at_most_k_distinct("eceba", 2) == 3
    assert longest_subarray_with_at_most_k_distinct("aa", 1) == 2
    print("✓ longest_subarray_with_at_most_k_distinct")
    
    print("\n✅ All tests passed!")
