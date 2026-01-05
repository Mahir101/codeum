"""
Sliding Window - Fixed Size Window
Template for problems like Maximum Average Subarray, Max Vowels in Substring
Time: O(n), Space: O(1)
"""

def max_average_subarray(nums, k):
    """
    LeetCode 643: Maximum Average Subarray I
    Find contiguous subarray of size k with maximum average.
    """
    if len(nums) < k:
        return 0.0
    
    # Calculate first window sum
    window_sum = sum(nums[:k])
    max_sum = window_sum
    
    # Slide the window
    for i in range(k, len(nums)):
        # Remove leftmost element, add rightmost element
        window_sum = window_sum - nums[i - k] + nums[i]
        max_sum = max(max_sum, window_sum)
    
    return max_sum / k


def max_vowels_in_substring(s, k):
    """
    LeetCode 1456: Maximum Number of Vowels in Substring
    Find max vowels in any substring of length k.
    """
    vowels = set('aeiouAEIOU')
    
    # Count vowels in first window
    current_count = sum(1 for c in s[:k] if c in vowels)
    max_count = current_count
    
    # Slide window
    for i in range(k, len(s)):
        # Remove left character
        if s[i - k] in vowels:
            current_count -= 1
        # Add right character
        if s[i] in vowels:
            current_count += 1
        max_count = max(max_count, current_count)
    
    return max_count


def find_max_consecutive_ones_k_flips(nums, k):
    """
    LeetCode 1004: Max Consecutive Ones III
    Max consecutive 1s after flipping at most k zeros.
    Fixed size window variant.
    """
    left = 0
    zeros_count = 0
    max_length = 0
    
    for right in range(len(nums)):
        if nums[right] == 0:
            zeros_count += 1
        
        # Shrink window if too many zeros
        while zeros_count > k:
            if nums[left] == 0:
                zeros_count -= 1
            left += 1
        
        max_length = max(max_length, right - left + 1)
    
    return max_length


# Test cases
if __name__ == "__main__":
    # Test max_average_subarray
    assert abs(max_average_subarray([1,12,-5,-6,50,3], 4) - 12.75) < 0.01
    print("✓ max_average_subarray")
    
    # Test max_vowels
    assert max_vowels_in_substring("abciiidef", 3) == 3
    assert max_vowels_in_substring("aeiou", 2) == 2
    print("✓ max_vowels_in_substring")
    
    # Test max consecutive ones
    assert find_max_consecutive_ones_k_flips([1,1,1,0,0,0,1,1,1,1,0], 2) == 6
    print("✓ find_max_consecutive_ones_k_flips")
    
    print("\n✅ All tests passed!")
