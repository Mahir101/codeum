# Two Pointers - All Patterns

## Pattern Recognition

Use Two Pointers when:
- Array/string is sorted
- Need to find pair/triplet with certain sum
- Remove/modify elements in-place
- Partition array
- Check for palindrome

---

## Pattern 1: Opposite Direction (Converging)

### Template
```python
def two_sum_sorted(arr, target):
    left, right = 0, len(arr) - 1
    
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return [-1, -1]
```

### Problems

1. **167. Two Sum II - Input Array Is Sorted** (Easy)
2. **15. 3Sum** (Medium)
   ```python
   def threeSum(nums):
       nums.sort()
       result = []
       
       for i in range(len(nums) - 2):
           if i > 0 and nums[i] == nums[i-1]:
               continue
           
           left, right = i + 1, len(nums) - 1
           while left < right:
               total = nums[i] + nums[left] + nums[right]
               if total == 0:
                   result.append([nums[i], nums[left], nums[right]])
                   while left < right and nums[left] == nums[left+1]:
                       left += 1
                   while left < right and nums[right] == nums[right-1]:
                       right -= 1
                   left += 1
                   right -= 1
               elif total < 0:
                   left += 1
               else:
                   right -= 1
       
       return result
   ```

3. **16. 3Sum Closest** (Medium)
4. **18. 4Sum** (Medium)
5. **11. Container With Most Water** (Medium)
6. **42. Trapping Rain Water** (Hard)

---

## Pattern 2: Same Direction (Fast & Slow)

### Template
```python
def remove_duplicates(arr):
    if not arr:
        return 0
    
    slow = 0
    for fast in range(1, len(arr)):
        if arr[fast] != arr[slow]:
            slow += 1
            arr[slow] = arr[fast]
    
    return slow + 1
```

### Problems

1. **26. Remove Duplicates from Sorted Array** (Easy)
2. **27. Remove Element** (Easy)
3. **283. Move Zeroes** (Easy)
4. **80. Remove Duplicates from Sorted Array II** (Medium)
5. **844. Backspace String Compare** (Easy)

---

## Pattern 3: Fast & Slow Pointers (Cycle Detection)

### Template
```python
def has_cycle(head):
    slow = fast = head
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            return True
    
    return False
```

### Problems

1. **141. Linked List Cycle** (Easy)
2. **142. Linked List Cycle II** (Medium) - Find cycle start
3. **202. Happy Number** (Easy) - Cycle detection in sequence
4. **287. Find the Duplicate Number** (Medium) - Floyd's algorithm
5. **876. Middle of the Linked List** (Easy)

---

## Pattern 4: Partition/Dutch National Flag

### Template
```python
def dutch_flag(arr):
    low, mid, high = 0, 0, len(arr) - 1
    
    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:  # arr[mid] == 2
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1
```

### Problems

1. **75. Sort Colors** (Medium) - Dutch National Flag
2. **905. Sort Array By Parity** (Easy)
3. **922. Sort Array By Parity II** (Easy)

---

## Pattern 5: Palindrome Checking

### Problems

1. **125. Valid Palindrome** (Easy)
2. **680. Valid Palindrome II** (Easy) - Remove one character
3. **234. Palindrome Linked List** (Easy)

---

## Pattern 6: Merge/Combine

### Problems

1. **88. Merge Sorted Array** (Easy)
2. **977. Squares of a Sorted Array** (Easy)
3. **986. Interval List Intersections** (Medium)

---

Total: **20 Two Pointer Patterns** covering **30+ Problems**
