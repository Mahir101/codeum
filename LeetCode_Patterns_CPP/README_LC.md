# 🎯 LeetCode Patterns Complete C++ Library

> **A comprehensive corpus of 290+ algorithm patterns covering 43 categories for mastering technical interviews**  
> **Based on Educative.io / Grokking the Coding Interview / NeetCode syllabus**

---

## 📚 Essential Resources

| Resource | Description |
|----------|-------------|
| [**VisuAlgo.net**](https://visualgo.net/en) | 🎨 Interactive algorithm visualizations - SEE algorithms in action |
| [LeetCode](https://leetcode.com) | Primary problem source |
| [NeetCode.io](https://neetcode.io) | Curated problem roadmap |
| [Educative.io](https://educative.io) | Grokking the Coding Interview |

---

## 🧠 THE DECISION TREE - How to Attack ANY Problem

```
                            ┌─────────────────────────┐
                            │    READ THE PROBLEM     │
                            └───────────┬─────────────┘
                                        │
                            ┌───────────▼─────────────┐
                            │  What type of INPUT?    │
                            └───────────┬─────────────┘
                                        │
         ┌──────────────┬───────────────┼───────────────┬──────────────┐
         ▼              ▼               ▼               ▼              ▼
    ┌─────────┐   ┌─────────┐    ┌─────────────┐  ┌─────────┐   ┌─────────┐
    │  ARRAY  │   │ STRING  │    │ LINKED LIST │  │  TREE   │   │  GRAPH  │
    └────┬────┘   └────┬────┘    └──────┬──────┘  └────┬────┘   └────┬────┘
         │             │                │              │             │
         ▼             ▼                ▼              ▼             ▼
   ┌───────────────────────────────────────────────────────────────────────┐
   │                    WHAT ARE WE DOING WITH IT?                        │
   └───────────────────────────────────────────────────────────────────────┘
         │
         ├─► "Find subarray/substring"        → SLIDING WINDOW
         ├─► "Find pair/triplet"              → TWO POINTERS (if sorted) / HASH MAP
         ├─► "Search in sorted"               → BINARY SEARCH
         ├─► "Find shortest path"             → BFS (unweighted) / DIJKSTRA (weighted)
         ├─► "Explore all possibilities"      → BACKTRACKING / DFS
         ├─► "Optimal value (overlapping)"    → DYNAMIC PROGRAMMING
         ├─► "Top K / Kth element"            → HEAP / QUICKSELECT
         ├─► "Prefix lookup / autocomplete"   → TRIE
         ├─► "Matching brackets"              → STACK
         ├─► "Merge K sorted"                 → K-WAY MERGE + HEAP
         ├─► "Union / Connected components"   → UNION-FIND
         ├─► "Range query + updates"          → SEGMENT TREE / BIT
         ├─► "Scheduling / overlapping"       → INTERVALS + SORT
         └─► "Game / min-max decision"        → GAME THEORY / MINIMAX
```

---

## 🔄 PATTERN SELECTION FLOWCHART

### Array/String Problems
```
Is the array SORTED?
├─ YES → TWO POINTERS or BINARY SEARCH
└─ NO
   ├─ Need contiguous subarray?
   │  └─ YES → SLIDING WINDOW
   ├─ Need frequency/existence?
   │  └─ YES → HASH MAP
   ├─ Need range queries?
   │  └─ YES → PREFIX SUM
   ├─ Need min/max in window?
   │  └─ YES → MONOTONIC DEQUE
   └─ Need next greater element?
      └─ YES → MONOTONIC STACK
```

### Tree Problems
```
What traversal needed?
├─ Level by level → BFS (Queue)
├─ Root to leaf paths → DFS (Recursion/Stack)
├─ Search in BST → O(h) Binary Search Property
├─ Lowest Common Ancestor → DFS with tracking
└─ Serialize/Deserialize → Preorder + markers
```

### Graph Problems
```
What are we finding?
├─ Shortest path (unweighted) → BFS
├─ Shortest path (weighted, +ve) → DIJKSTRA
├─ Shortest path (negative edges) → BELLMAN-FORD
├─ All paths / Explore fully → DFS
├─ Cycle detection → DFS with colors / Union-Find
├─ Connected components → DFS / BFS / Union-Find
├─ Topological order → KAHN'S BFS / DFS
├─ Minimum spanning tree → KRUSKAL / PRIM
└─ Bridges / Articulation → TARJAN
```

### Dynamic Programming Problems
```
Can I define state clearly?
├─ State = single value → 1D DP
├─ State = two values → 2D DP
├─ State = subset → BITMASK DP
│
What's the recurrence?
├─ Take or not take → KNAPSACK pattern
├─ Try all splits → INTERVAL DP  
├─ Depends on previous k → SLIDING WINDOW DP
└─ Multiple choices → MIN/MAX over choices
```

---

## 🎯 THE 10 PRIMITIVE OPERATIONS

*Every algorithm is composed of these 10 fundamental operations:*

| Primitive | Operation | Example Use |
|-----------|-----------|-------------|
| **P0** | COMPARE | `<`, `>`, `==`, `min`, `max` - Every decision |
| **P1** | ACCUMULATE | `sum`, `count`, prefix sums - Building state |
| **P2** | BRANCH | `if/else`, `switch` - Conditional logic |
| **P3** | REPEAT | `for`, `while` - Iteration |
| **P4** | REMEMBER | Memoization, caching - Avoid recomputation |
| **P5** | FORGET | Sliding window, pruning - Discard irrelevant |
| **P6** | REWIND | Backtracking, undo - Explore alternatives |
| **P7** | COMPRESS | RLE, coordinate compression - Reduce space |
| **P8** | EXPAND | Generate neighbors - BFS/DFS transitions |
| **P9** | APPROXIMATE | Binary search on answer, estimation |

---

## 📊 Complete Pattern Coverage (43 Categories)

### 🔢 Core Data Structure Patterns (1-18)

| # | Pattern | Files | Key Techniques | Time Complexity |
|---|---------|-------|----------------|-----------------|
| **01** | Arrays & Hashing | 15 | HashMap, HashSet, Counting | O(n) average |
| **02** | Two Pointers | 16 | Left/Right, Fast/Slow | O(n) |
| **03** | Sliding Window | 9 | Fixed/Variable window, Shrink | O(n) |
| **04** | Stack | 17 | Monotonic, Expression parsing | O(n) |
| **05** | Binary Search | 9 | Sorted, Rotated, Search on Answer | O(log n) |
| **06** | Linked List | 11 | Reverse, Merge, Fast/Slow | O(n) |
| **07** | Trees | 16 | Traversals, BST, LCA, Binary Lifting | O(n) to O(log n) |
| **08** | Tries | 7 | Prefix search, Autocomplete | O(L) per operation |
| **09** | Heap / Priority Queue | 9 | Top-K, Merge K Sorted | O(log n) per op |
| **10** | Backtracking | 12 | Permutations, Combinations, Pruning | O(n!) to O(2^n) |
| **11** | Graphs | 10 | BFS, DFS, Islands, Flood Fill | O(V+E) |
| **12** | Advanced Graphs | 15 | Dijkstra, Union-Find, MST, Tarjan | O(E log V) |
| **13** | 1D Dynamic Programming | 17 | Linear DP, State Machine | O(n) to O(n²) |
| **14** | 2D Dynamic Programming | 18 | Grid, String matching, Intervals | O(n²) to O(n³) |
| **15** | Greedy | 7 | Locally optimal, Scheduling | O(n log n) |
| **16** | Intervals | 7 | Merge, Overlap, Line Sweep | O(n log n) |
| **17** | Math & Geometry | 8 | Primes, GCD, Modular arithmetic | Varies |
| **18** | Bit Manipulation | 4 | XOR tricks, Bit counting | O(1) to O(n) |

### 🚀 Grokking Patterns (19-31)

| # | Pattern | Files | Problem Type | Key Insight |
|---|---------|-------|--------------|-------------|
| **19** | Fast & Slow Pointers | 4 | Cycle detection, Middle | Two speeds meet in cycle |
| **20** | Cyclic Sort | 3 | Numbers in range [1,n] | Place each at its index |
| **21** | In-Place Reversal | 3 | Modify linked list | Reverse pointers |
| **22** | Tree BFS | 4 | Level order, Width | Process level by level |
| **23** | Tree DFS | 6 | Path problems, Subtrees | Recursion with returns |
| **24** | Two Heaps | 3 | Median, Balance | Min + Max heap |
| **25** | Subsets Pattern | 3 | Generate combinations | BFS/DFS add elements |
| **26** | Modified Binary Search | 3 | Rotated, Unknown size | Adapt boundaries |
| **27** | Bitwise XOR | 3 | Find unique/missing | a⊕a=0, a⊕0=a |
| **28** | Top K Elements | 3 | K largest/smallest | Heap of size K |
| **29** | K-Way Merge | 3 | Merge K sorted lists | Min-heap of heads |
| **30** | 0/1 Knapsack | 3 | Take or not take | dp[i][w] = max |
| **31** | Topological Sort | 4 | Dependencies, DAG | Kahn's or DFS |

### 🔥 Advanced Patterns (32-42)

| # | Pattern | Files | When to Use | Complexity |
|---|---------|-------|-------------|------------|
| **32** | String Pattern Matching | 3 | Substring search | O(n+m) KMP |
| **33** | Matrix Traversal | 3 | Spiral, Diagonal walk | O(m×n) |
| **34** | Monotonic Stack | 4 | Next greater/smaller | O(n) |
| **35** | Prefix Sum | 4 | Range sum queries | O(1) query |
| **36** | Counting Pattern | 3 | Majority, Frequency | O(n) |
| **37** | Simulation | 3 | Game of Life, Robot | O(steps) |
| **38** | Design Patterns | 5 | LRU, RandomSet | O(1) operations |
| **39** | Divide & Conquer | 4 | Merge sort counting | O(n log n) |
| **40** | Game Theory | 3 | Minimax, Nim | O(states) |
| **41** | Segment Tree | 3 | Range query + update | O(log n) |
| **42** | Fenwick Tree (BIT) | 3 | Prefix sum updates | O(log n) |

---

## 🎨 ALGORITHM COMPLEXITY CHEAT SHEET

```
┌────────────────────────────────────────────────────────────────────────────┐
│                        TIME COMPLEXITY COMPARISON                          │
├────────────────────────────────────────────────────────────────────────────┤
│  O(1)       < O(log n)   < O(n)      < O(n log n) < O(n²)    < O(2ⁿ)      │
│  HashMap      Binary      Linear       Merge Sort   Nested     Subsets     │
│  Array idx    Search      Scan         Quick Sort   Loops      Backtrack   │
├────────────────────────────────────────────────────────────────────────────┤
│  n = 10⁶:                                                                  │
│  O(n²) = 10¹² operations ≈ 16 minutes  ❌ TLE                              │
│  O(n log n) = 2×10⁷ operations ≈ 0.02 seconds ✅                           │
│  O(n) = 10⁶ operations ≈ 0.001 seconds ✅                                  │
└────────────────────────────────────────────────────────────────────────────┘
```

### What Complexity Works for Given Input Size?

| Input Size (n) | Max Complexity | Time (approx) |
|----------------|----------------|---------------|
| n ≤ 10 | O(n!) | Brute force works |
| n ≤ 20 | O(2ⁿ) | Bitmask DP |
| n ≤ 500 | O(n³) | Floyd-Warshall |
| n ≤ 5,000 | O(n²) | Simple DP |
| n ≤ 10⁶ | O(n log n) | Sorting-based |
| n ≤ 10⁸ | O(n) | Linear scan |
| n ≤ 10¹² | O(log n) | Binary search |

---

## 🔧 TECHNIQUE COMBINATIONS (Pattern Mixtures)

### Common Pattern Combinations

| Combination | Use Case | Example Problems |
|-------------|----------|------------------|
| **Hash Map + Two Pointers** | Two Sum variants | LC 1, 167, 15 |
| **Binary Search + Greedy** | Minimize maximum | LC 875, 1011, 410 |
| **BFS + Hash Set** | Shortest transformation | LC 127, 752 |
| **DFS + Memoization** | Tree/Graph DP | LC 124, 337, 329 |
| **Sliding Window + Hash Map** | Substring with constraints | LC 3, 76, 438 |
| **Heap + Two Pointers** | Median in stream | LC 295, 480 |
| **Union-Find + Sort** | MST, Connected components | LC 1584, 547 |
| **Monotonic Stack + DP** | Histogram, Largest rectangle | LC 84, 85 |
| **Prefix Sum + Hash Map** | Subarray sum equals K | LC 560, 523 |
| **Trie + Backtracking** | Word search II | LC 212 |
| **Segment Tree + Coordinate Compression** | Range queries on sparse data | LC 315, 493 |
| **Binary Lifting + LCA** | Tree ancestor queries | LC 1483, 236 |

### Advanced Technique Stacks

```
Multi-Source BFS:
├── Add all sources to queue initially
├── BFS level by level
└── Used for: Rotting Oranges (994), Walls and Gates (286)

Bidirectional BFS:
├── BFS from both start and end
├── Meet in the middle
└── Used for: Word Ladder (127), shorter path finding

Topological Sort + DP:
├── Topo sort to get processing order
├── DP following that order
└── Used for: Course Schedule III, Parallel Courses

Binary Search on Answer + Greedy Check:
├── Binary search the answer value
├── Greedy verify if answer is achievable
└── Used for: Koko Bananas (875), Ship Packages (1011)

Monotonic Stack + Contribution:
├── Find span of element being min/max
├── Calculate contribution of each element
└── Used for: Sum of Subarray Minimums (907)
```

---

## 📝 PROBLEM-SOLVING CHECKLIST

### Before Coding
```
□ Read problem 2-3 times
□ Identify input/output types
□ Note constraints (n ≤ ?)
□ Think of edge cases
□ Draw examples
□ Identify pattern category
□ Consider time/space requirements
```

### Pattern Recognition Questions
```
1. Is it asking for shortest/minimum? → BFS/DP/Binary Search
2. Is it asking for all possibilities? → Backtracking
3. Is it optimization with choices? → DP
4. Does order matter? → Permutation, not combination
5. Can I sort without losing info? → Two Pointers/Greedy
6. Is there a monotonic property? → Binary Search/Stack
7. Can I break into subproblems? → Divide & Conquer/DP
8. Is there overlapping computation? → Memoization
```

### During Coding
```
□ Handle edge cases first (empty, single element)
□ Use meaningful variable names
□ Comment tricky parts
□ Test with examples mentally
□ Check off-by-one errors
□ Verify loop bounds
□ Consider integer overflow
```

---

## 🚀 Quick Start

```bash
# Clone and explore
cd LeetCode_Patterns_CPP

# Compile any file
g++ -std=c++17 -O2 -o solution 01_Arrays_Hashing/003_two_sum.cpp && ./solution

# Verify all files compile
find . -name "*.cpp" -exec g++ -std=c++17 -fsyntax-only {} \;

# Count files and lines
echo "Files: $(find . -name '*.cpp' | wc -l)"
echo "Lines: $(find . -name '*.cpp' -exec wc -l {} + | tail -1)"
```

---

## 📚 12-Week Study Plan

| Week | Topics | Patterns | Daily Problems |
|------|--------|----------|----------------|
| 1 | Arrays, Hashing | 01, 02, 03 | 3-4 |
| 2 | Two Pointers, Sliding Window | 02, 03, 19 | 3-4 |
| 3 | Stack, Binary Search | 04, 05, 34 | 3-4 |
| 4 | Linked List, Fast/Slow | 06, 19, 21 | 3-4 |
| 5 | Trees (BFS, DFS) | 07, 22, 23 | 3-4 |
| 6 | Graphs Basics | 11, 31 | 3-4 |
| 7 | Heap, Two Heaps | 09, 24, 28 | 3-4 |
| 8 | 1D DP, Knapsack | 13, 30 | 3-4 |
| 9 | 2D DP, Intervals | 14, 16 | 3-4 |
| 10 | Advanced Graphs | 12 | 3-4 |
| 11 | Tries, Backtracking | 08, 10 | 3-4 |
| 12 | Advanced (Segment Tree, etc.) | 41, 42, 39, 40 | 3-4 |

---

## 📈 Library Statistics

| Metric | Count |
|--------|-------|
| **Pattern Categories** | 43 |
| **C++ Files** | 291 |
| **Lines of Code** | 14,600+ |
| **LeetCode Problems Covered** | 500+ |
| **Algorithms Implemented** | 150+ |
| **Data Structures** | 30+ |

---

## 🎯 Quick Pattern Reference

### By Problem Type

| Problem Says... | Think... | Pattern |
|-----------------|----------|---------|
| "Contiguous subarray" | Sliding window | 03 |
| "Pair that sums to" | Hash map or two pointers | 01, 02 |
| "Shortest path" | BFS (unweighted), Dijkstra (weighted) | 11, 12 |
| "All combinations/permutations" | Backtracking | 10 |
| "Maximum/minimum satisfaction" | DP or Greedy | 13, 14, 15 |
| "Top K" | Heap | 09, 28 |
| "Prefix matches" | Trie | 08 |
| "Valid parentheses" | Stack | 04 |
| "Cycle in linked list" | Fast/Slow pointers | 19 |
| "Connected components" | Union-Find or DFS | 12 |
| "Range sum queries" | Prefix Sum or Segment Tree | 35, 41 |
| "Next greater element" | Monotonic Stack | 34 |
| "Merge intervals" | Sort + Greedy | 16 |

### By Constraint Size

| n ≤ | Patterns That Work |
|-----|-------------------|
| 10 | Any (even O(n!)) |
| 20 | Bitmask DP O(2ⁿ) |
| 100 | O(n³) Floyd-Warshall |
| 1,000 | O(n²) Simple DP |
| 100,000 | O(n log n) Sorting, Heap |
| 1,000,000 | O(n) Linear, Two Pointers |
| 10⁹ | O(log n) Binary Search |

---

## 🌟 Visualization Resources

- **[VisuAlgo.net](https://visualgo.net/en)** - Interactive algorithm animations
- **[Algorithm Visualizer](https://algorithm-visualizer.org)** - Code + visualization
- **[USF Visualization](https://www.cs.usfca.edu/~galles/visualization)** - Data structure animations
- **[PathFinding.js](https://qiao.github.io/PathFinding.js/visual/)** - Graph algorithm visualizer

---

**Master these patterns, master the interview!** 🚀

*Built with ❤️ for coding interview preparation*

---

```
"The patterns are the map. The primitives are the compass."
— Algorithm Design Philosophy
```
