# LeetCode Pattern Library - Master Index

## Overview

This is a comprehensive collection of **300+ problem-solving patterns** distilled from analyzing 2000+ LeetCode problems. Every problem can be solved using combinations of these patterns.

---

## Pattern Categories (30 Main Categories)

### 1. Array Patterns (35 patterns)
### 2. String Patterns (30 patterns)
### 3. Linked List Patterns (15 patterns)
### 4. Stack & Queue Patterns (20 patterns)
### 5. Heap Patterns (12 patterns)
### 6. Tree Patterns (40 patterns)
### 7. Graph Patterns (35 patterns)
### 8. Dynamic Programming Patterns (50 patterns)
### 9. Greedy Patterns (20 patterns)
### 10. Backtracking Patterns (18 patterns)
### 11. Recursion Patterns (15 patterns)
### 12. Divide & Conquer Patterns (12 patterns)
### 13. Binary Search Patterns (18 patterns)
### 14. Sliding Window Patterns (15 patterns)
### 15. Two Pointers Patterns (20 patterns)
### 16. Hash Table Patterns (15 patterns)
### 17. Design Patterns (12 patterns)
### 18. Math Patterns (20 patterns)
### 19. Bit Manipulation Patterns (15 patterns)
### 20. Sorting Patterns (12 patterns)
### 21. Interval Patterns (10 patterns)
### 22. Monotonic Stack/Queue Patterns (12 patterns)
### 23. Trie Patterns (8 patterns)
### 24. Union-Find Patterns (10 patterns)
### 25. Topological Sort Patterns (8 patterns)
### 26. BFS Patterns (15 patterns)
### 27. DFS Patterns (18 patterns)
### 28. Matrix Patterns (15 patterns)
### 29. Simulation Patterns (10 patterns)
### 30. Advanced Hybrid Patterns (20 patterns)

**Total: ~350 Patterns**

---

## Quick Pattern Recognition Guide

When you see a problem, ask these questions in order:

### 1. What is the input type?
- **Array/String** → Consider: Sliding Window, Two Pointers, Prefix Sum, Binary Search
- **Tree** → Consider: DFS, BFS, Recursion, Tree DP
- **Graph** → Consider: DFS, BFS, Union-Find, Shortest Path, Topological Sort
- **LinkedList** → Consider: Fast & Slow Pointers, Reversal, Merge
- **Matrix** → Consider: DFS/BFS, DP, Simulation

### 2. What is the goal?
- **Find substring/subarray** → Sliding Window, Two Pointers
- **Find all permutations/combinations** → Backtracking
- **Optimize choices** → DP, Greedy
- **Shortest path** → BFS, Dijkstra
- **Detect cycle** → Floyd's Algorithm, DFS
- **Interval operations** → Sorting + Greedy/Sweep Line

### 3. What are the constraints?
- **Small input (n ≤ 20)** → Backtracking, Brute Force, Bitmask DP
- **Medium (n ≤ 1000)** → O(n²) DP possible
- **Large (n ≤ 10⁵)** → Need O(n log n) or O(n)
- **Very large (n ≤ 10⁶)** → Must be O(n) or better

### 4. Pattern Keywords
- **"Contiguous"** → Sliding Window
- **"All possible"** → Backtracking
- **"Optimal"** → DP, Greedy
- **"K elements"** → Heap, QuickSelect
- **"Parentheses"** → Stack
- **"Graph connected components"** → Union-Find, DFS
- **"Range queries"** → Prefix Sum, Segment Tree

---

## Directory Structure

```
LeetCode Patterns/
├── Array/
│   ├── 01_PrefixSum.md
│   ├── 02_Kadane_MaxSubarray.md
│   ├── 03_DutchNationalFlag.md
│   ├── ...
├── SlidingWindow/
│   ├── 01_FixedSizeWindow.md
│   ├── 02_VariableSizeWindow.md
│   ├── 03_MultiplePointers.md
│   ├── ...
├── DynamicProgramming/
│   ├── 01_0-1_Knapsack.md
│   ├── 02_UnboundedKnapsack.md
│   ├── 03_LCS_LongestCommonSubsequence.md
│   ├── ...
└── [28 more categories]
```

---

## Pattern Complexity Matrix

| Pattern | Time | Space | Difficulty | Use Cases |
|---------|------|-------|------------|-----------|
| Sliding Window | O(n) | O(1) | Easy | Subarray/substring problems |
| Two Pointers | O(n) | O(1) | Easy | Sorted arrays, palindromes |
| Fast & Slow Pointers | O(n) | O(1) | Medium | Cycle detection, middle element |
| Merge Intervals | O(n log n) | O(n) | Medium | Overlapping intervals |
| Cyclic Sort | O(n) | O(1) | Easy | Missing number, duplicates |
| In-place Reversal | O(n) | O(1) | Medium | Reverse linked list |
| Tree BFS | O(n) | O(n) | Medium | Level-order traversal |
| Tree DFS | O(n) | O(h) | Medium | Path problems, recursion |
| Binary Search | O(log n) | O(1) | Medium | Sorted search |
| Top K Elements | O(n log k) | O(k) | Medium | K largest/smallest |
| K-way Merge | O(N log k) | O(k) | Hard | Merge sorted lists |
| 0/1 Knapsack | O(n·W) | O(n·W) | Medium | Subset problems |
| Unbounded Knapsack | O(n·W) | O(W) | Medium | Coin change, rod cutting |
| Topological Sort | O(V+E) | O(V) | Medium | Task scheduling, dependencies |
| Backtracking | O(b^d) | O(d) | Hard | Permutations, combinations |

---

## Core Pattern Groups

### Group 1: Array/String Manipulation (100+ patterns)
- Prefix techniques
- Sliding mechanisms  
- Pointer strategies
- Sorting algorithms
- Search variations

### Group 2: Tree Structures (60+ patterns)
- Traversal methods
- Path finding
- Construction techniques
- BST operations
- Lowest Common Ancestor variations

### Group 3: Graph Algorithms (50+ patterns)
- Search strategies (BFS/DFS variants)
- Shortest paths
- Connected components
- Topological ordering
- Minimum spanning trees

### Group 4: Dynamic Programming (50+ patterns)
- Linear DP
- 2D DP
- Subsequence patterns
- String DP
- Tree DP
- Bitmask DP
- Digit DP
- DP on graphs

### Group 5: Greedy & Optimization (30+ patterns)
- Interval scheduling
- Huffman coding variants
- Activity selection  
- Fractional problems
- Exchange arguments

### Group 6: Advanced Techniques (60+ patterns)
- Monotonic structures
- Binary indexed trees
- Segment trees
- Trie variations
- Union-Find optimizations
- Bit manipulation tricks

---

## Master Pattern Knowledge Graph

See `PATTERN_CONNECTIONS.md` for the complete interconnection graph showing:
- Which patterns build on others
- When to combine multiple patterns
- Pattern → Algorithm mapping
- Real LeetCode problems for each pattern

---

## How to Use This Library

1. **Identify the pattern** from problem description
2. **Navigate to category folder**
3. **Read pattern file** with:
   - Pattern explanation
   - Template code
   - 5-10 example problems
   - Variations and edge cases
4. **Practice problems** in order of difficulty
5. **Connect patterns** using the knowledge graph

---

## Pattern Mastery Roadmap

### Phase 1: Fundamentals (Weeks 1-4)
- Array basics (Prefix Sum, Two Pointers)
- String basics
- Linked List basics
- Stack & Queue
- Basic Tree (BFS, DFS)

### Phase 2: Intermediate (Weeks 5-12)
- Sliding Window (all variants)
- Binary Search (all variants)
- Tree DP
- Graph basics (BFS, DFS, Union-Find)
- Basic DP patterns

### Phase 3: Advanced (Weeks 13-24)
- All DP patterns (50 patterns)
- Advanced Graph (Shortest paths, MST)
- Backtracking (all patterns)
- Segment Tree, BIT
- Monotonic patterns

### Phase 4: Mastery (Weeks 25-52)
- Hard DP patterns
- Advanced data structures
- Pattern combinations
- Problem solving under time pressure
- Contest-level patterns

---

## Statistics

- **Total Patterns**: 350+
- **Total Example Problems**: 2000+
- **Categories**: 30
- **Difficulty Distribution**:
  - Easy: 30%
  - Medium: 50%
  - Hard: 20%

---

## Next: Dive into individual pattern files!

Start with `/Array/01_PrefixSum.md` or jump to any category that interests you.
