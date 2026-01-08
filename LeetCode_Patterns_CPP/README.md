# 🎯 LeetCode Patterns Complete C++ Library

> **A comprehensive corpus of 167+ algorithm patterns covering 43 categories for mastering technical interviews**
> **Based on Educative.io / Grokking the Coding Interview syllabus**

## 📊 All 43 Pattern Categories

| # | Pattern | Key Problems |
|---|---------|--------------|
| **01** | Arrays & Hashing | Two Sum, Valid Anagram, Group Anagrams, Top K Frequent |
| **02** | Two Pointers | 3Sum, Container Water, Trapping Rain Water |
| **03** | Sliding Window | Longest Substring, Minimum Window, Max Sliding |
| **04** | Stack | Valid Parentheses, Monotonic Stack, Histogram |
| **05** | Binary Search | Classic, Rotated Array, Search on Answer |
| **06** | Linked List | Reverse, Merge, LRU/LFU Cache |
| **07** | Trees | Traversals, BST Validation, LCA, Serialize |
| **08** | Tries | Implement Trie, Word Search, Dictionary |
| **09** | Heap / Priority Queue | Kth Largest, Merge K Lists, Task Scheduler |
| **10** | Backtracking | Permutations, Subsets, N-Queens, Sudoku |
| **11** | Graphs | BFS, DFS, Islands, Clone Graph |
| **12** | Advanced Graphs | Dijkstra, Union-Find, MST, Topological Sort |
| **13** | 1D Dynamic Programming | House Robber, Coin Change, LIS, Word Break |
| **14** | 2D Dynamic Programming | Edit Distance, LCS, Longest Path, Stock Prices |
| **15** | Greedy | Jump Game, Gas Station, Candy, Scheduling |
| **16** | Intervals | Merge, Meeting Rooms, Insert Interval |
| **17** | Math & Geometry | Rotate Image, Power, Spiral Matrix |
| **18** | Bit Manipulation | Single Number, Counting Bits, XOR Tricks |
| **19** | Fast & Slow Pointers | Cycle Detection, Middle of List, Happy Number |
| **20** | Cyclic Sort | Missing Number, Find Duplicates, First Missing |
| **21** | In-Place Reversal | Reverse Between, Swap Pairs, K-Group |
| **22** | Tree BFS | Level Order, Zigzag, Min Depth, Right Side View |
| **23** | Tree DFS | Path Sum, Root to Leaf, Binary Tree Paths |
| **24** | Two Heaps | Find Median, Sliding Window Median, IPO |
| **25** | Subsets Pattern | Generate Subsets, Letter Case Permutation |
| **26** | Modified Binary Search | Peak Element, Single in Sorted, Mountain Array |
| **27** | Bitwise XOR | Single Number III, Complement, Flip Image |
| **28** | Top K Elements | Kth Largest, K Closest Points, Frequency Sort |
| **29** | K-Way Merge | Merge K Lists, Kth in Matrix, K Pairs Sums |
| **30** | 0/1 Knapsack | Partition Equal, Target Sum, Last Stone |
| **31** | Topological Sort | Course Schedule, Alien Dictionary, Min Height Trees |
| **32** | String Pattern Matching | KMP, Rabin-Karp, Repeated Substring |
| **33** | Matrix Traversal | Spiral, Diagonal, Toeplitz Matrix |
| **34** | Monotonic Stack | Daily Temperatures, Histogram, Subarray Mins |
| **35** | Prefix Sum | Range Sum, Subarray Sum K, Product Except Self |
| **36** | Counting Pattern | Majority Element, Top K Frequent, Consecutive |
| **37** | Simulation | Zigzag, Game of Life, Josephus Problem |
| **38** | Design Patterns | RandomizedSet, HashMap Design, LRU Cache |
| **39** | Divide & Conquer | Merge Sort, Count Smaller, Sort List |
| **40** | Game Theory | Nim, Stone Game, Predict Winner, Can I Win |
| **41** | Segment Tree | Range Sum Mutable, Lazy Propagation |
| **42** | Fenwick Tree (BIT) | Prefix Sum Updates, 2D Range Queries |
| **P0** | Primitives | Basic patterns and templates |

## 🧠 Pattern Recognition Framework

```
┌─────────────────────────────────────────────────────────────────────────────┐
│ CONTIGUOUS SUBARRAY/SUBSTRING         → Sliding Window                     │
│ SORTED ARRAY + PAIR FINDING           → Two Pointers                       │
│ SHORTEST PATH (UNWEIGHTED)            → BFS                                │
│ EXPLORE ALL PATHS                     → DFS / Backtracking                 │
│ OPTIMAL + OVERLAPPING SUBPROBLEMS     → Dynamic Programming                │
│ SEARCH IN SORTED                      → Binary Search                      │
│ MATCHING/NESTING                      → Stack                              │
│ PREFIX SEARCH                         → Trie                               │
│ TOP/BOTTOM K                          → Heap                               │
│ MERGE K SORTED                        → K-Way Merge + Heap                 │
│ CONNECTED COMPONENTS                  → Union-Find                         │
│ WEIGHTED SHORTEST PATH                → Dijkstra                           │
│ CYCLE DETECTION                       → DFS / Fast-Slow / Union-Find       │
│ TASK DEPENDENCIES                     → Topological Sort                   │
│ RANGE QUERIES + UPDATES               → Segment Tree / Fenwick Tree        │
│ NUMBERS IN RANGE [1,N]                → Cyclic Sort                        │
│ MIN/MAX IN WINDOW                     → Monotonic Deque                    │
│ FIND UNIQUE / MISSING                 → XOR / Math                         │
└─────────────────────────────────────────────────────────────────────────────┘
```

## 🚀 Quick Start

```bash
# Compile any file
g++ -std=c++17 -O2 -o solution 01_Arrays_Hashing/003_two_sum.cpp && ./solution

# Compile all and verify syntax
find . -name "*.cpp" -exec g++ -std=c++17 -fsyntax-only {} \;
```

## 📚 Study Plan (Educative-Style)

### Week 1-2: Foundation Patterns
- 01 Arrays & Hashing
- 02 Two Pointers  
- 03 Sliding Window
- 19 Fast & Slow Pointers

### Week 3-4: Data Structure Patterns
- 04 Stack / 34 Monotonic Stack
- 06 Linked List / 21 In-Place Reversal
- 05 Binary Search / 26 Modified Binary Search

### Week 5-6: Tree/Graph Patterns
- 22 Tree BFS / 23 Tree DFS
- 11 Graphs (BFS/DFS)
- 31 Topological Sort

### Week 7-8: DP Patterns
- 13 1D DP / 14 2D DP
- 30 0/1 Knapsack
- 25 Subsets Pattern

### Week 9-10: Advanced Patterns
- 12 Advanced Graphs (Dijkstra, MST, Union-Find)
- 41 Segment Tree / 42 Fenwick Tree
- 40 Game Theory

### Week 11-12: Optimization & Design
- 15 Greedy / 16 Intervals
- 38 Design Patterns
- 32 String Pattern Matching

---

## 📈 Statistics

| Metric | Count |
|--------|-------|
| Pattern Categories | 43 |
| C++ Files | 167 |
| Lines of Code | 8,245+ |
| LeetCode Problems | 300+ |

---

**Master these patterns, master the interview!** 🌟
