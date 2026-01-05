# Dynamic Programming - All Patterns

## 50 DP Patterns Organized by Type

---

## Category 1: Linear DP (10 patterns)

### Pattern 1.1: Single Sequence DP

**Problems:**
- 70. Climbing Stairs
- 746. Min Cost Climbing Stairs
- 198. House Robber
- 213. House Robber II (circular)
- 740. Delete and Earn

**Template:**
```python
def solve(arr):
    dp = [0] * (len(arr) + 1)
    dp[0] = base_case_0
    dp[1] = base_case_1
    
    for i in range(2, len(arr) + 1):
        dp[i] = max/min(dp[i-1] + cost, dp[i-2] + cost)
    
    return dp[n]
```

---

### Pattern 1.2: Two Sequences DP (String Matching)

**Problems:**
-1143. Longest Common Subsequence (LCS)
- 72. Edit Distance
- 583. Delete Operation for Two Strings
- 712. Minimum ASCII Delete Sum
- 115. Distinct Subsequences

**Template:**
```python
def lcs(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[m][n]
```

---

## Category 2: Knapsack DP (8 patterns)

### Pattern 2.1: 0/1 Knapsack (Subset Selection)

**Problems:**
- 416. Partition Equal Subset Sum
- 494. Target Sum
- 1049. Last Stone Weight II

**Template:**
```python
def knapsack(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            if weights[i-1] <= w:
                dp[i][w] = max(dp[i-1][w], 
                    dp[i-1][w - weights[i-1]] + values[i-1])
            else:
                dp[i][w] = dp[i-1][w]
    
    return dp[n][capacity]
```

---

### Pattern 2.2: Unbounded Knapsack

**Problems:**
- 322. Coin Change
- 518. Coin Change II
- 377. Combination Sum IV
- 139. Word Break
- 983. Minimum Cost For Tickets

**Template:**
```python
def unbounded_knapsack(items, target):
    dp = [float('inf')] * (target + 1)
    dp[0] = 0
    
    for i in range(1, target + 1):
        for item in items:
            if i >= item:
                dp[i] = min(dp[i], dp[i - item] + 1)
    
    return dp[target]
```

---

## Category 3: Substring/Subarray DP (10 patterns)

### Pattern 3.1: Palindrome DP

**Problems:**
- 5. Longest Palindromic Substring
- 647. Palindromic Substrings
- 516. Longest Palindromic Subsequence
- 1312. Minimum Insertion Steps to Make String Palindrome

**Template:**
```python
def longest_palindrome(s):
    n = len(s)
    dp = [[False] * n for _ in range(n)]
    max_len = 1
    start = 0
    
    # Every single character is palindrome
    for i in range(n):
        dp[i][i] = True
    
    # Check for length 2
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            dp[i][i + 1] = True
            start = i
            max_len = 2
    
    # Check for lengths > 2
    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j] and dp[i + 1][j - 1]:
                dp[i][j] = True
                start = i
                max_len = length
    
    return s[start:start + max_len]
```

---

### Pattern 3.2: Maximum Subarray

**Problems:**
- 53. Maximum Subarray (Kadane's)
- 152. Maximum Product Subarray
- 918. Maximum Sum Circular Subarray

**Template:**
```python
# Kadane's Algorithm
def max_subarray(nums):
    max_sum = nums[0]
    current_sum = nums[0]
    
    for i in range(1, len(nums)):
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)
    
    return max_sum
```

---

## Category 4: Grid/Matrix DP (8 patterns)

### Pattern 4.1: Path in Grid

**Problems:**
- 62. Unique Paths
- 63. Unique Paths II
- 64. Minimum Path Sum
- 120. Triangle
- 931. Minimum Falling Path Sum

**Template:**
```python
def unique_paths(m, n):
    dp = [[0] * n for _ in range(m)]
    
    # Initialize first row and column
    for i in range(m):
        dp[i][0] = 1
    for j in range(n):
        dp[0][j] = 1
    
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
    return dp[m-1][n-1]
```

---

## Category 5: Tree DP (5 patterns)

### Pattern 5.1: Binary Tree DP

**Problems:**
- 96. Unique Binary Search Trees
- 95. Unique Binary Search Trees II
- 337. House Robber III
- 543. Diameter of Binary Tree
- 124. Binary Tree Maximum Path Sum

**Template:**
```python
def rob_tree(root):
    def dfs(node):
        if not node:
            return (0, 0)  # (rob, not_rob)
        
        left = dfs(node.left)
        right = dfs(node.right)
        
        rob = node.val + left[1] + right[1]
        not_rob = max(left) + max(right)
        
        return (rob, not_rob)
    
    return max(dfs(root))
```

---

## Category 6: State Machine DP (4 patterns)

### Pattern 6.1: Buy/Sell Stock

**Problems:**
- 121. Best Time to Buy and Sell Stock
- 122. Best Time to Buy and Sell Stock II
- 123. Best Time to Buy and Sell Stock III
- 188. Best Time to Buy and Sell Stock IV
- 309. Best Time to Buy and Sell Stock with Cooldown
- 714. Best Time to Buy and Sell Stock with Transaction Fee

**Template:**
```python
def maxProfit(prices):
    # States: hold (have stock), sold (just sold), rest (no stock, can buy)
    hold = -prices[0]
    sold = 0
    rest = 0
    
    for price in prices[1:]:
        prev_hold = hold
        prev_sold = sold
        prev_rest = rest
        
        hold = max(prev_hold, prev_rest - price)
        sold = prev_hold + price
        rest = max(prev_rest, prev_sold)
    
    return max(sold, rest)
```

---

## Category 7: Interval DP (3 patterns)

### Pattern 7.1: Burst Balloons Type

**Problems:**
- 312. Burst Balloons
- 1039. Minimum Score Triangulation of Polygon
- 664. Strange Printer

**Template:**
```python
def burst_balloons(nums):
    nums = [1] + nums + [1]
    n = len(nums)
    dp = [[0] * n for _ in range(n)]
    
    # length is gap between left and right
    for length in range(2, n):
        for left in range(n - length):
            right = left + length
            for i in range(left + 1, right):
                dp[left][right] = max(dp[left][right],
                    dp[left][i] + nums[left] * nums[i] * nums[right] + dp[i][right])
    
    return dp[0][n-1]
```

---

## Category 8: Bitmask DP (3 patterns)

### Pattern 8.1: Traveling Salesman / Hamiltonian Path

**Problems:**
- 847. Shortest Path Visiting All Nodes
- 943. Find the Shortest Superstring
- 1125. Smallest Sufficient Team
- 1595. Minimum Cost to Connect Two Groups of Points

**Template:**
```python
def shortest_path_all_nodes(graph):
    n = len(graph)
    # dp[mask][i] = min cost to reach state mask ending at node i
    dp = [[float('inf')] * n for _ in range(1 << n)]
    
    # Start from each node
    for i in range(n):
        dp[1 << i][i] = 0
    
    for mask in range(1 << n):
        for i in range(n):
            if mask & (1 << i):
                for j in graph[i]:
                    new_mask = mask | (1 << j)
                    dp[new_mask][j] = min(dp[new_mask][j], dp[mask][i] + 1)
    
    final_mask = (1 << n) - 1
    return min(dp[final_mask])
```

---

## Category 9: Digit DP (2 patterns)

### Pattern 9.1: Count Numbers with Property

**Problems:**
- 233. Number of Digit One
- 357. Count Numbers with Unique Digits
- 902. Numbers At Most N Given Digit Set
- 1012. Numbers With Repeated Digits

**Template:**
```python
def digit_dp(n):
    s = str(n)
    memo = {}
    
    def dp(pos, tight, started, [other_states]):
        if pos == len(s):
            return 1 if started else 0
        
        state = (pos, tight, started, [other_states])
        if state in memo:
            return memo[state]
        
        limit = int(s[pos]) if tight else 9
        result = 0
        
        for digit in range(0, limit + 1):
            new_tight = tight and (digit == limit)
            new_started = started or (digit != 0)
            result += dp(pos + 1, new_tight, new_started, [new_states])
        
        memo[state] = result
        return result
    
    return dp(0, True, False, [initial_states])
```

---

## Category 10: Game Theory DP (3 patterns)

### Pattern 10.1: Minimax DP

**Problems:**
- 486. Predict the Winner
- 877. Stone Game
- 1140. Stone Game II
- 1406. Stone Game III
- 1510. Stone Game IV

**Template:**
```python
def stone_game(piles):
    n = len(piles)
    # dp[i][j] = max score difference (current - opponent) for piles[i:j+1]
    dp = [[0] * n for _ in range(n)]
    
    # Base case: single pile
    for i in range(n):
        dp[i][i] = piles[i]
    
    # Fill diagonally
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
    
    return dp[0][n-1] > 0
```

---

## Category 11: DP with Data Structures (4 patterns)

### Pattern 11.1: DP + Monotonic Stack

**Problems:**
- 975. Odd Even Jump
- 1537. Get the Maximum Score

### Pattern 11.2: DP + Segment Tree

**Problems:**
- 307. Range Sum Query - Mutable
- 1039. Min Score Triangulation

---

## Summary Table

| Category | Patterns | Difficulty | Key Technique |
|----------|----------|------------|---------------|
| Linear DP | 10 | Easy-Medium | 1D/2D array |
| Knapsack | 8 | Medium | Subset selection |
| Substring | 10 | Medium | Range DP |
| Grid | 8 | Easy-Medium | Path counting |
| Tree | 5 | Medium-Hard | Recursion + memo |
| State Machine | 4 | Medium | Finite states |
| Interval | 3 | Hard | Range merging |
| Bitmask | 3 | Hard | Subset enumeration |
| Digit | 2 | Hard | Position-based |
| Game Theory | 3 | Medium-Hard | Minimax |
| With DS | 4 | Hard | Hybrid approach |

---

Total: **50 DP Patterns** covering **200+ LeetCode Problems**
