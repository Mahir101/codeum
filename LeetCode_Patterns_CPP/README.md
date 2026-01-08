# 🎯 LeetCode Patterns Complete C++ Library

> **A comprehensive corpus of 290+ algorithm patterns covering 43 categories for mastering technical interviews**
> **Based on Educative.io / Grokking the Coding Interview syllabus**

---

## 📊 Complete Pattern Coverage (43 Categories)

### 🔢 Core Patterns (Patterns 1-18)
| # | Pattern | Files | Key Problems |
|---|---------|-------|--------------|
| **01** | Arrays & Hashing | 15 | Two Sum, Valid Anagram, Group Anagrams, Encode/Decode |
| **02** | Two Pointers | 16 | 3Sum, Container Water, Trapping Rain, 4Sum |
| **03** | Sliding Window | 9 | Longest Substring, Min Window, Permutation in String |
| **04** | Stack | 17 | Valid Parentheses, Calculator, Asteroid Collision |
| **05** | Binary Search | 9 | Rotated Array, Koko Bananas, Ship Packages |
| **06** | Linked List | 11 | Reverse, Merge K, LRU Cache, Add Two Numbers |
| **07** | Trees | 16 | Traversals, BST, LCA, Serialize, Binary Lifting |
| **08** | Tries | 7 | Implement Trie, Word Search II, Autocomplete |
| **09** | Heap / Priority Queue | 9 | Kth Largest, Merge K Lists, Task Scheduler |
| **10** | Backtracking | 12 | Permutations, N-Queens, Sudoku, Expression Add |
| **11** | Graphs | 10 | BFS, DFS, Islands, Pacific Atlantic, Large Island |
| **12** | Advanced Graphs | 15 | Dijkstra, Union-Find, MST, Bellman-Ford, Tarjan |
| **13** | 1D Dynamic Programming | 17 | House Robber, Coin Change, LIS, Frog Jump |
| **14** | 2D Dynamic Programming | 18 | Edit Distance, LCS, Regex, Bitmask DP |
| **15** | Greedy | 7 | Jump Game, Gas Station, Task Scheduler |
| **16** | Intervals | 7 | Merge, Meeting Rooms, Skyline, Calendar |
| **17** | Math & Geometry | 8 | Rotate Image, Primes, Division, Roman |
| **18** | Bit Manipulation | 4 | Single Number, Counting Bits, Hamming |

### 🚀 Educative Grokking Patterns (Patterns 19-31)
| # | Pattern | Files | Key Problems |
|---|---------|-------|--------------|
| **19** | Fast & Slow Pointers | 4 | Cycle Detection, Middle, Happy Number, Reorder |
| **20** | Cyclic Sort | 3 | Missing Number, Find Duplicates, First Missing |
| **21** | In-Place Reversal | 3 | Reverse Between, Swap Pairs, K-Group |
| **22** | Tree BFS | 4 | Level Order, Zigzag, Next Right, Width |
| **23** | Tree DFS | 6 | Path Sum, Root to Leaf, Max Path, Distance |
| **24** | Two Heaps | 3 | Find Median, Sliding Median, Right Interval |
| **25** | Subsets Pattern | 3 | Subsets, Combinations, Letter Combinations |
| **26** | Modified Binary Search | 3 | Peak Element, Mountain Array, Infinite Array |
| **27** | Bitwise XOR | 3 | Single Number III, Missing Number, Range AND |
| **28** | Top K Elements | 3 | Kth Largest, Reorganize String, Task Scheduler |
| **29** | K-Way Merge | 3 | Merge K Lists, Smallest Range, Ugly Numbers |
| **30** | 0/1 Knapsack | 3 | Partition Equal, Target Sum, Ones Zeroes |
| **31** | Topological Sort | 4 | Course Schedule, Alien Dictionary, Parallel |

### 🔥 Advanced Patterns (Patterns 32-42)
| # | Pattern | Files | Key Problems |
|---|---------|-------|--------------|
| **32** | String Pattern Matching | 3 | KMP, Z-Algorithm, Manacher |
| **33** | Matrix Traversal | 3 | Spiral, Diagonal, Sudoku Validation |
| **34** | Monotonic Stack | 4 | Daily Temperatures, Histogram, Next Greater II |
| **35** | Prefix Sum | 4 | Range Sum, 2D Prefix, Difference Array |
| **36** | Counting Pattern | 3 | Majority Element, Top K Frequent, Kth Missing |
| **37** | Simulation | 3 | Game of Life, Robot Simulation, Zigzag |
| **38** | Design Patterns | 5 | LRU/LFU, RandomizedSet, FreqStack, All O(1) |
| **39** | Divide & Conquer | 4 | Merge Sort, Reverse Pairs, Ways to Compute |
| **40** | Game Theory | 3 | Nim, Stone Game, Predict Winner |
| **41** | Segment Tree | 3 | Range Sum Mutable, Lazy Propagation, LIS |
| **42** | Fenwick Tree (BIT) | 3 | Prefix Sum Updates, Count Smaller, Inversions |

---

## 🧠 Pattern Recognition Framework

```
┌─────────────────────────────────────────────────────────────────────────────┐
│ KEYWORD / SCENARIO                    → PATTERN                            │
├─────────────────────────────────────────────────────────────────────────────┤
│ Contiguous subarray/substring         → Sliding Window                     │
│ Sorted array + pair finding           → Two Pointers                       │
│ Shortest path (unweighted)            → BFS                                │
│ Explore all paths / combinations      → DFS / Backtracking                 │
│ Optimal + overlapping subproblems     → Dynamic Programming                │
│ Search in sorted / minimize maximum   → Binary Search                      │
│ Matching/nesting brackets             → Stack                              │
│ Prefix search / autocomplete          → Trie                               │
│ Top/Bottom K elements                 → Heap                               │
│ Merge K sorted sources                → K-Way Merge + Heap                 │
│ Connected components                  → Union-Find                         │
│ Weighted shortest path                → Dijkstra / Bellman-Ford            │
│ Cycle detection (linked list)         → Fast-Slow Pointers                 │
│ Cycle detection (graph)               → DFS / Union-Find                   │
│ Task dependencies / ordering          → Topological Sort                   │
│ Range queries with updates            → Segment Tree / Fenwick Tree        │
│ Numbers in range [1,N]                → Cyclic Sort                        │
│ Min/Max in sliding window             → Monotonic Deque                    │
│ Find unique / missing (XOR trick)     → Bitwise XOR                        │
│ Stream median / balance               → Two Heaps                          │
│ Generate all subsets                  → Subsets Pattern (BFS)              │
│ String pattern matching               → KMP / Z-Algorithm                  │
│ Game optimal play                     → Game Theory / Minimax              │
└─────────────────────────────────────────────────────────────────────────────┘
```

---

## 🚀 Quick Start

```bash
# Compile any file
g++ -std=c++17 -O2 -o solution 01_Arrays_Hashing/003_two_sum.cpp && ./solution

# Compile all and verify syntax
find . -name "*.cpp" -exec g++ -std=c++17 -fsyntax-only {} \;

# Count files and lines
find . -name "*.cpp" | wc -l
find . -name "*.cpp" -exec wc -l {} + | tail -1
```

---

## 📚 Recommended Study Order (12-Week Plan)

### Weeks 1-2: Foundation
- ✅ 01 Arrays & Hashing
- ✅ 02 Two Pointers  
- ✅ 03 Sliding Window
- ✅ 19 Fast & Slow Pointers

### Weeks 3-4: Data Structures
- ✅ 04 Stack / 34 Monotonic Stack
- ✅ 06 Linked List / 21 In-Place Reversal
- ✅ 05 Binary Search / 26 Modified Binary Search

### Weeks 5-6: Trees & Graphs
- ✅ 07 Trees / 22 Tree BFS / 23 Tree DFS
- ✅ 11 Graphs (BFS/DFS)
- ✅ 31 Topological Sort

### Weeks 7-8: Dynamic Programming
- ✅ 13 1D DP / 14 2D DP
- ✅ 30 0/1 Knapsack
- ✅ 25 Subsets Pattern

### Weeks 9-10: Advanced Patterns
- ✅ 12 Advanced Graphs (Dijkstra, MST, Union-Find)
- ✅ 41 Segment Tree / 42 Fenwick Tree
- ✅ 40 Game Theory

### Weeks 11-12: Optimization & System Design
- ✅ 15 Greedy / 16 Intervals
- ✅ 38 Design Patterns
- ✅ 32 String Pattern Matching (KMP, Manacher)

---

## 📈 Library Statistics

| Metric | Count |
|--------|-------|
| **Pattern Categories** | 43 |
| **C++ Files** | 291 |
| **Lines of Code** | 14,600+ |
| **LeetCode Problems Covered** | 500+ |
| **Time Complexities Documented** | All |
| **Space Complexities Documented** | All |

---

## 🎯 Pattern-to-Problem Quick Reference

| If you see... | Think... | Example Problems |
|---------------|----------|------------------|
| "Subarray sum" | Prefix Sum / Sliding Window | LC 560, 523, 974 |
| "K largest/smallest" | Heap | LC 215, 347, 973 |
| "Linked list cycle" | Fast/Slow Pointers | LC 141, 142, 287 |
| "Tree level" | BFS | LC 102, 103, 199 |
| "All paths/combinations" | Backtracking | LC 39, 46, 78 |
| "Shortest path" | BFS/Dijkstra | LC 127, 743, 1631 |
| "Minimum/Maximum with constraint" | DP or Binary Search | LC 300, 410, 875 |
| "Parentheses matching" | Stack | LC 20, 32, 921 |
| "Word dictionary" | Trie | LC 208, 211, 212 |
| "Merge intervals" | Sort + Greedy | LC 56, 57, 986 |
| "Graph connectivity" | Union-Find | LC 200, 547, 684 |
| "Range query + update" | Segment Tree | LC 307, 315, 493 |

---

**Master these patterns, master the interview!** 🌟

*Built with ❤️ for coding interview preparation*
