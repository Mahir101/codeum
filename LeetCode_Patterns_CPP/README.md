# 🎯 LeetCode Patterns Complete C++ Library

> **A comprehensive corpus of 116+ algorithm patterns and problem solutions for mastering technical interviews**

## 📊 Pattern Coverage

| Category | Files | Key Patterns |
|----------|-------|--------------|
| **01_Arrays_Hashing** | 15 | Hash Set, Frequency Map, Prefix Sum, Cyclic Sort, Boyer-Moore |
| **02_Two_Pointers** | 15 | Converging, Fast/Slow, Dutch Flag, 3Sum, Container Water |
| **03_Sliding_Window** | 4 | Variable Size (Max/Min), Fixed Size, Character Replacement |
| **04_Stack** | 15 | Matching, Monotonic, Evaluation, Histogram, Next Greater |
| **05_Binary_Search** | 4 | Classic, Lower/Upper Bound, Search on Answer, Rotated Array |
| **06_Linked_List** | 6 | Reversal, Cycle Detection, Merge, Two Pointers, K-Group |
| **07_Trees** | 7 | DFS/BFS, BST Validation, LCA, Construction, Path Sum |
| **08_Tries** | 3 | Prefix Tree, Wildcard Search, Word Search II |
| **09_Heap_PriorityQueue** | 4 | Top K, K-way Merge, Two Heaps, Median Stream |
| **10_Backtracking** | 6 | Permutations, Subsets, Combinations, N-Queens, Partition |
| **11_Graphs** | 5 | BFS Shortest Path, DFS, Islands, Clone, Connectivity |
| **12_Advanced_Graphs** | 5 | Topological Sort, Union Find, Dijkstra, MST, Bellman-Ford |
| **13_1D_DP** | 7 | Fibonacci, Knapsack, LIS, House Robber, Word Break |
| **14_2D_DP** | 6 | Grid Paths, Edit Distance, LCS, Palindrome, Stock Prices |
| **15_Greedy** | 3 | Jump Game, Gas Station, Candy, Scheduling |
| **16_Intervals** | 4 | Merge, Meeting Rooms, Insert, Intersection |
| **17_Math_Geometry** | 3 | Matrix Rotation, Fast Power, Spiral |
| **18_Bit_Manipulation** | 3 | XOR Tricks, Counting Bits, Sum without Plus |

## 🧠 Learning Philosophy

Each file contains:
```
✓ Pattern Recognition Cues - How to identify when to use this pattern
✓ Problem Analysis - How to attack and break down the problem
✓ Brain Training Notes - How to internalize and practice the pattern
✓ Multiple Variations - Related problems using the same technique
✓ Complexity Analysis - Time and space breakdown
```

## 🚀 Quick Start

```bash
# Compile any file
g++ -std=c++17 -O2 -o solution 01_Arrays_Hashing/003_two_sum.cpp && ./solution

# Compile all and check for errors
for f in */*.cpp; do g++ -std=c++17 -fsyntax-only "$f" && echo "✓ $f"; done
```

## 📚 Pattern Recognition Cheat Sheet

```
┌────────────────────────────────────────────────────────────────────────────┐
│ "Contiguous subarray/substring" → SLIDING WINDOW                          │
│ "Sorted array + find pair" → TWO POINTERS                                 │
│ "Shortest path unweighted" → BFS                                          │
│ "Find all paths / explore" → DFS / BACKTRACKING                           │
│ "Optimal/counting" + "overlapping subproblems" → DYNAMIC PROGRAMMING      │
│ "Search in sorted" → BINARY SEARCH                                        │
│ "Matching brackets/nesting" → STACK                                       │
│ "Prefix search" → TRIE                                                    │
│ "Top/Bottom K elements" → HEAP                                            │
│ "Merge K sorted" → K-WAY MERGE + HEAP                                     │
│ "Connected components" → UNION FIND                                       │
│ "Weighted shortest path" → DIJKSTRA                                       │
│ "Detect cycle in graph" → DFS/UNION FIND                                  │
│ "Task ordering with dependencies" → TOPOLOGICAL SORT                      │
└────────────────────────────────────────────────────────────────────────────┘
```

## 🎓 Recommended Study Order

1. **Foundation** (Week 1-2): Arrays/Hashing, Two Pointers, Sliding Window
2. **Data Structures** (Week 3-4): Stack, Linked List, Trees, Binary Search
3. **Graph Fundamentals** (Week 5): BFS, DFS, Basic Graph Problems
4. **Advanced** (Week 6-7): Dynamic Programming (1D then 2D)
5. **Optimization** (Week 8): Greedy, Intervals, Advanced Graphs
6. **Mastery** (Week 9+): Backtracking, Tries, Bit Manipulation, Heaps

## 📈 Complexity Reference

| Pattern | Typical Time | Typical Space |
|---------|-------------|---------------|
| Hash Table Lookup | O(1) | O(n) |
| Two Pointers | O(n) | O(1) |
| Sliding Window | O(n) | O(1) to O(k) |
| Binary Search | O(log n) | O(1) |
| DFS/BFS | O(V + E) | O(V) |
| Heap Operations | O(log n) | O(n) |
| DP (1D) | O(n) to O(n²) | O(n) |
| DP (2D) | O(m × n) | O(m × n) |
| Backtracking | O(2^n) to O(n!) | O(n) |
| Union Find | O(α(n)) ≈ O(1) | O(n) |
| Dijkstra | O((V+E) log V) | O(V) |

---

**Total: 116 pattern files | 18 categories | 200+ LeetCode problems covered**

*Keep practicing, keep growing!* 🌟
