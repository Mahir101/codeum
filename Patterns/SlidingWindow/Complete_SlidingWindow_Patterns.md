# Sliding Window Patterns

## Overview

Sliding Window is one of the most important patterns for array/string problems. It's used when you need to find a **contiguous subarray or substring** that satisfies certain conditions.

**Time Complexity**: Usually O(n)  
**Space Complexity**: Usually O(1) or O(k) for window

---

## Pattern Recognition

Use Sliding Window when you see these keywords:
- "contiguous subarray/substring"
- "longest/shortest substring with X property"
- "maximum/minimum sum of size K"
- "find all anagrams/permutations"

---

## Types of Sliding Window

### 1. Fixed Size Window
Window size k is given. Slide and calculate.

### 2. Variable Size Window - Maximum
Expand window while condition holds, track maximum.

### 3. Variable Size Window - Minimum
Shrink window while condition holds, track minimum.

### 4. Variable Size Window - Exact Match
Find window that exactly matches condition.

---

## Pattern 1: Fixed Size Window

### Template

```python
def fixed_window(arr, k):
    if len(arr) < k:
        return None
    
    # Calculate first window
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    # Slide the window
    for i in range(k, len(arr)):
        window_sum = window_sum - arr[i - k] + arr[i]
        max_sum = max(max_sum, window_sum)
    
    return max_sum
```

### LeetCode Problems

1. **643. Maximum Average Subarray I** (Easy)
   - Given: array `nums`, integer `k`
   - Find: maximum average of contiguous subarray of size k
   
2. **1456. Maximum Number of Vowels in a Substring of Given Length** (Medium)
   - Count vowels in sliding window of size k

3. **1052. Grumpy Bookstore Owner** (Medium)
   - Maximize satisfied customers using technique for k minutes

---

## Pattern 2: Variable Size Window (Longest/Maximum)

### Template

```python
def longest_subarray_with_condition(arr):
    left = 0
    max_length = 0
    window_state = {}  # Track window properties
    
    for right in range(len(arr)):
        # Expand window: add arr[right]
        # Update window_state with arr[right]
        
        # Shrink window while condition violated
        while condition_violated(window_state):
            # Remove arr[left] from window_state
            left += 1
        
        # Update result
        max_length = max(max_length, right - left + 1)
    
    return max_length
```

### LeetCode Problems

1. **3. Longest Substring Without Repeating Characters** (Medium)
   - Use hash set to track characters
   - Shrink when duplicate found
   
   ```python
   def lengthOfLongestSubstring(s):
       char_set = set()
       left = 0
       max_len = 0
       
       for right in range(len(s)):
           while s[right] in char_set:
               char_set.remove(s[left])
               left += 1
           char_set.add(s[right])
           max_len = max(max_len, right - left + 1)
       
       return max_len
   ```

2. **424. Longest Repeating Character Replacement** (Medium)
   - Can replace k characters
   - Track max frequency in window
   - Shrink when (window_size - max_freq) > k

3. **1004. Max Consecutive Ones III** (Medium)
   - Can flip k zeros
   - Very similar to above

4. **1493. Longest Subarray of 1's After Deleting One Element** (Medium)
   - Special case: must delete one element

---

## Pattern 3: Variable Size Window (Shortest/Minimum)

### Template

```python
def shortest_subarray_with_condition(arr, target):
    left = 0
    min_length = float('inf')
    window_sum = 0
    
    for right in range(len(arr)):
        window_sum += arr[right]
        
        # Shrink window while condition met
        while window_sum >= target:
            min_length = min(min_length, right - left + 1)
            window_sum -= arr[left]
            left += 1
    
    return min_length if min_length != float('inf') else 0
```

### LeetCode Problems

1. **209. Minimum Size Subarray Sum** (Medium)
   - Find shortest subarray with sum ≥ target
   
2. **76. Minimum Window Substring** (Hard) ⭐
   - Find smallest window containing all characters of `t`
   
   ```python
   def minWindow(s, t):
       if not s or not t:
           return ""
       
       # Count characters needed
       dict_t = Counter(t)
       required = len(dict_t)
       
       # Sliding window counters
       left, right = 0, 0
       formed = 0  # How many unique chars in window match target frequency
       window_counts = {}
       
       ans = float('inf'), None, None  # (window length, left, right)
       
       while right < len(s):
           # Expand window
           char = s[right]
           window_counts[char] = window_counts.get(char, 0) + 1
           
           if char in dict_t and window_counts[char] == dict_t[char]:
               formed += 1
           
           # Shrink window
           while left <= right and formed == required:
               char = s[left]
               
               # Update result
               if right - left + 1 < ans[0]:
                   ans = (right - left + 1, left, right)
               
               # Remove from window
               window_counts[char] -= 1
               if char in dict_t and window_counts[char] < dict_t[char]:
                   formed -= 1
               
               left += 1
           
           right += 1
       
       return "" if ans[0] == float('inf') else s[ans[1]:ans[2] + 1]
   ```

3. **727. Minimum Window Subsequence** (Hard)
   - Find shortest substring of s that contains t as subsequence

---

## Pattern 4: Count Subarrays with Exact Condition

### Template

```python
def count_subarrays_with_exactly_k(arr, k):
    return at_most_k(arr, k) - at_most_k(arr, k - 1)

def at_most_k(arr, k):
    left = 0
    count = 0
    window_state = 0
    
    for right in range(len(arr)):
        # Update window state with arr[right]
        
        while window_state > k:
            # Remove arr[left]
            left += 1
        
        # All subarrays ending at right are valid
        count += right - left + 1
    
    return count
```

### LeetCode Problems

1. **992. Subarrays with K Different Integers** (Hard)
   - Count subarrays with exactly k distinct integers
   - Use at_most(k) - at_most(k-1) trick

2. **1248. Count Number of Nice Subarrays** (Medium)
   - Subarray with exactly k odd numbers

3. **930. Binary Subarrays With Sum** (Medium)
   - Subarray with sum exactly equal to goal

---

## Pattern 5: Multiple Conditions Window

### LeetCode Problems

1. **438. Find All Anagrams in a String** (Medium)
   - Fixed size window + character frequency matching
   
   ```python
   def findAnagrams(s, p):
       if len(s) < len(p):
           return []
       
       p_count = Counter(p)
       s_count = Counter(s[:len(p)])
       result = []
       
       if s_count == p_count:
           result.append(0)
       
       for i in range(len(p), len(s)):
           # Add new char
           s_count[s[i]] += 1
           # Remove old char
           s_count[s[i - len(p)]] -= 1
           if s_count[s[i - len(p)]] == 0:
               del s_count[s[i - len(p)]]
           
           if s_count == p_count:
               result.append(i - len(p) + 1)
       
       return result
   ```

2. **567. Permutation in String** (Medium)
   - Check if permutation of s1 exists in s2
   - Same as anagram problem

---

## Pattern 6: String Matching Variants

### LeetCode Problems

1. **159. Longest Substring with At Most Two Distinct Characters** (Medium)
2. **340. Longest Substring with At Most K Distinct Characters** (Medium)
3. **395. Longest Substring with At Least K Repeating Characters** (Medium)
4. **1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit** (Medium)

---

## Pattern 7: Specialized Sliding Window

### LeetCode Problems

1. **1423. Maximum Points You Can Obtain from Cards** (Medium)
   - Take x cards from beginning or end
   - Equivalent to finding minimum sum of middle (n-k) cards

2. **713. Subarray Product Less Than K** (Medium)
   - Count subarrays with product < k
   - Use shrinking window

3. **862. Shortest Subarray with Sum at Least K** (Hard)
   - With negative numbers - need deque for prefix sums

4. **904. Fruit Into Baskets** (Medium)
   - At most 2 types - longest subarray with at most 2 distinct

---

## Common Mistakes

1. **Off-by-one errors**: Be careful with `right - left + 1`
2. **Forgetting to remove from left**: Must update window state when shrinking
3. **Wrong shrink condition**: While vs if
4. **Not handling edge cases**: Empty array, k > n

---

## Complexity Analysis

- **Time**: O(n) - each element visited at most twice (once by right, once by left)
- **Space**: O(k) or O(1) depending on window state tracking

---

## When NOT to Use Sliding Window

- Need non-contiguous elements → Consider DP or Hash Table
- Need all subsets → Backtracking
- Need to compare non-adjacent elements → Two Pointers or DP

---

## Related Patterns

- **Two Pointers**: Similar but not necessarily contiguous
- **Prefix Sum**: For range sum queries
- **Monotonic Queue**: For sliding window maximum/minimum efficiently
- **Deque**: For sliding window median

---

Total Problems: **15 core patterns** covering **50+ LeetCode questions**
