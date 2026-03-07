/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║                    PRIMITIVE OPERATIONS (P0-P9)                           ║
 * ║                  The Atoms of Algorithm Design                            ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * Every algorithm ever written is composed of these 10 primitive operations.
 * Master these, and you master the building blocks of computational thinking.
 * 
 * Brain Mapping: These operations mirror how our brain processes information
 * - P0 Compare: Prefrontal cortex (evaluation/judgment)
 * - P1 Accumulate: Working memory (chunking data)
 * - P2 Branch: Decision gating (neural fork)
 * - P3 Repeat: Motor repetition circuits
 * - P4 Remember: Working → long-term memory transfer
 * - P5 Forget: Attention pruning (ignore irrelevant)
 * - P6 Rewind: Mental simulation/imagination
 * - P7 Compress: Abstraction circuits
 * - P8 Expand: Spatial reasoning
 * - P9 Approximate: Intuition/heuristics
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <climits>
#include <sstream>
#include <list>
#include <iomanip>
using namespace std;

// ═══════════════════════════════════════════════════════════════════════════
// P0. COMPARE - The Foundation of All Decisions
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: <, >, ==, min, max, dominates
 * Hidden use: Every condition, invariant, feasibility check
 * Why fundamental: No decision exists without comparison
 * 
 * "If an algorithm 'chooses,' it compares."
 */

namespace P0_Compare {
    
    // Basic comparisons
    template<typename T>
    bool isLess(const T& a, const T& b) { return a < b; }
    
    template<typename T>
    bool isGreater(const T& a, const T& b) { return a > b; }
    
    template<typename T>
    bool isEqual(const T& a, const T& b) { return a == b; }
    
    // Multi-dimensional dominance
    // Point A dominates Point B if A is better in ALL dimensions
    template<typename T>
    bool dominates(const vector<T>& a, const vector<T>& b) {
        if (a.size() != b.size()) return false;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] <= b[i]) return false;  // Must be strictly better
        }
        return true;
    }
    
    // Pareto dominance (used in multi-objective optimization)
    // A Pareto dominates B if A is >= in all dims and > in at least one
    template<typename T>
    bool paretoDominates(const vector<T>& a, const vector<T>& b) {
        if (a.size() != b.size()) return false;
        bool strictlyBetter = false;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] < b[i]) return false;
            if (a[i] > b[i]) strictlyBetter = true;
        }
        return strictlyBetter;
    }
    
    // Three-way comparison (C++20 spaceship operator emulation)
    template<typename T>
    int threeWayCompare(const T& a, const T& b) {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }
    
    // Custom comparator for complex objects
    struct Task {
        int id, priority, deadline;
    };
    
    bool taskComparator(const Task& a, const Task& b) {
        if (a.priority != b.priority) return a.priority > b.priority;  // Higher priority first
        if (a.deadline != b.deadline) return a.deadline < b.deadline;  // Earlier deadline first
        return a.id < b.id;  // Stable sort by id
    }
    
    // Lexicographic comparison
    template<typename T>
    int lexCompare(const vector<T>& a, const vector<T>& b) {
        size_t n = min(a.size(), b.size());
        for (size_t i = 0; i < n; i++) {
            if (a[i] < b[i]) return -1;
            if (a[i] > b[i]) return 1;
        }
        return threeWayCompare(a.size(), b.size());
    }
    
    // Example: Find minimum and maximum in array
    pair<int, int> findMinMax(const vector<int>& arr) {
        if (arr.empty()) return {INT_MAX, INT_MIN};
        int minVal = arr[0], maxVal = arr[0];
        for (int x : arr) {
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }
        return {minVal, maxVal};
    }
    
    // Example: Binary Search - Pure comparison-based algorithm
    int binarySearch(const vector<int>& arr, int target) {
        int lo = 0, hi = arr.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P1. ACCUMULATE - Building State Through Aggregation
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: sum, count, prefix, suffix, aggregate
 * Hidden use: Prefix sums, DP transitions, frequency tables
 * Why fundamental: State grows by accumulation, not recomputation
 */

namespace P1_Accumulate {
    
    // Basic sum accumulation
    template<typename T>
    T sum(const vector<T>& arr) {
        T result = T();
        for (const T& x : arr) result += x;
        return result;
    }
    
    // Prefix sum - O(1) range queries after O(n) preprocessing
    class PrefixSum {
        vector<long long> prefix;
    public:
        PrefixSum(const vector<int>& arr) {
            prefix.resize(arr.size() + 1, 0);
            for (size_t i = 0; i < arr.size(); i++) {
                prefix[i + 1] = prefix[i] + arr[i];
            }
        }
        
        // Query sum of range [l, r] (inclusive, 0-indexed)
        long long query(int l, int r) {
            return prefix[r + 1] - prefix[l];
        }
    };
    
    // 2D Prefix Sum for matrix range queries
    class PrefixSum2D {
        vector<vector<long long>> prefix;
    public:
        PrefixSum2D(const vector<vector<int>>& matrix) {
            int m = matrix.size(), n = m ? matrix[0].size() : 0;
            prefix.assign(m + 1, vector<long long>(n + 1, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    prefix[i + 1][j + 1] = matrix[i][j] 
                        + prefix[i][j + 1] 
                        + prefix[i + 1][j] 
                        - prefix[i][j];
                }
            }
        }
        
        // Query sum of submatrix [r1, c1] to [r2, c2] (inclusive)
        long long query(int r1, int c1, int r2, int c2) {
            return prefix[r2 + 1][c2 + 1] 
                 - prefix[r1][c2 + 1] 
                 - prefix[r2 + 1][c1] 
                 + prefix[r1][c1];
        }
    };
    
    // Suffix sum
    class SuffixSum {
        vector<long long> suffix;
    public:
        SuffixSum(const vector<int>& arr) {
            int n = arr.size();
            suffix.resize(n + 1, 0);
            for (int i = n - 1; i >= 0; i--) {
                suffix[i] = suffix[i + 1] + arr[i];
            }
        }
        
        long long query(int i) { return suffix[i]; }
    };
    
    // XOR prefix (useful for subarray XOR queries)
    class PrefixXOR {
        vector<int> prefix;
    public:
        PrefixXOR(const vector<int>& arr) {
            prefix.resize(arr.size() + 1, 0);
            for (size_t i = 0; i < arr.size(); i++) {
                prefix[i + 1] = prefix[i] ^ arr[i];
            }
        }
        
        int query(int l, int r) { return prefix[r + 1] ^ prefix[l]; }
    };
    
    // Running product with modulo
    class PrefixProduct {
        vector<long long> prefix;
        long long MOD;
    public:
        PrefixProduct(const vector<int>& arr, long long mod = 1e9 + 7) : MOD(mod) {
            prefix.resize(arr.size() + 1, 1);
            for (size_t i = 0; i < arr.size(); i++) {
                prefix[i + 1] = (prefix[i] * arr[i]) % MOD;
            }
        }
        
        long long getPrefix(int i) { return prefix[i + 1]; }
    };
    
    // Frequency accumulation (counting sort foundation)
    vector<int> frequencyCount(const vector<int>& arr, int maxVal) {
        vector<int> freq(maxVal + 1, 0);
        for (int x : arr) freq[x]++;
        return freq;
    }
    
    // Cumulative frequency (useful for counting inversions, rank queries)
    vector<int> cumulativeFrequency(const vector<int>& freq) {
        vector<int> cum(freq.size());
        cum[0] = freq[0];
        for (size_t i = 1; i < freq.size(); i++) {
            cum[i] = cum[i - 1] + freq[i];
        }
        return cum;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P2. BRANCH - Conditional Flow Control
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: if / else / case split
 * Hidden use: Greedy choices, DP transitions, pruning
 * Why fundamental: All algorithms are conditional flow graphs
 */

namespace P2_Branch {
    
    // If-else pattern
    template<typename T>
    T clamp(T value, T minVal, T maxVal) {
        if (value < minVal) return minVal;
        if (value > maxVal) return maxVal;
        return value;
    }
    
    // Multi-branch (switch-case pattern)
    enum Direction { UP, DOWN, LEFT, RIGHT };
    
    pair<int, int> move(pair<int, int> pos, Direction dir) {
        switch (dir) {
            case UP:    return {pos.first - 1, pos.second};
            case DOWN:  return {pos.first + 1, pos.second};
            case LEFT:  return {pos.first, pos.second - 1};
            case RIGHT: return {pos.first, pos.second + 1};
            default:    return pos;
        }
    }
    
    // Ternary branching (common in DP)
    int editDistanceTransition(int replace, int insert, int del) {
        return 1 + min({replace, insert, del});
    }
    
    // Early exit pattern (pruning)
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;  // Early exit - branch prunes
        }
        return true;
    }
    
    // Guard clause pattern
    int safeDivide(int a, int b) {
        if (b == 0) return 0;  // Guard
        return a / b;
    }
    
    // Decision tree pattern (used in game theory, minimax)
    int minmaxDecision(int depth, bool isMaximizing, vector<int>& leaves, int& idx) {
        if (depth == 0) return leaves[idx++];
        
        int left = minmaxDecision(depth - 1, !isMaximizing, leaves, idx);
        int right = minmaxDecision(depth - 1, !isMaximizing, leaves, idx);
        
        if (isMaximizing) return max(left, right);
        else return min(left, right);
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P3. REPEAT - Controlled Iteration
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: loop, iterate, traverse
 * Hidden use: Scans, BFS layers, DFS recursion
 * Why fundamental: Computation = controlled repetition
 */

namespace P3_Repeat {
    
    // For loop - counting iteration
    void linearScan(const vector<int>& arr) {
        for (size_t i = 0; i < arr.size(); i++) {
            // Process arr[i]
        }
    }
    
    // While loop - condition-based iteration
    int countDigits(int n) {
        if (n == 0) return 1;
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count;
    }
    
    // Do-while loop - guaranteed first execution
    int findFirstSetBit(int n) {
        int pos = 0;
        do {
            if (n & 1) return pos;
            n >>= 1;
            pos++;
        } while (n > 0);
        return -1;
    }
    
    // Nested loops - O(n²) patterns
    int countPairs(const vector<int>& arr, int target) {
        int count = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = i + 1; j < arr.size(); j++) {
                if (arr[i] + arr[j] == target) count++;
            }
        }
        return count;
    }
    
    // Iterator-based loop
    template<typename Container>
    void iteratorTraversal(Container& c) {
        for (auto it = c.begin(); it != c.end(); ++it) {
            // Process *it
        }
    }
    
    // BFS layer iteration
    vector<vector<int>> bfsLayers(const vector<vector<int>>& graph, int start) {
        vector<vector<int>> layers;
        vector<bool> visited(graph.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            vector<int> layer;
            int size = q.size();
            for (int i = 0; i < size; i++) {  // Repeat for each level
                int node = q.front(); q.pop();
                layer.push_back(node);
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            layers.push_back(layer);
        }
        return layers;
    }
    
    // Recursion as implicit repetition
    long long factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P4. REMEMBER - State Persistence (Memoization)
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: store state
 * Hidden use: Hash maps, DP tables, visited sets
 * Why fundamental: Without memory, exponential blowup
 */

namespace P4_Remember {
    
    // HashMap for state storage
    class TwoSumSolver {
        unordered_map<int, int> seen;
    public:
        pair<int, int> twoSum(const vector<int>& nums, int target) {
            for (int i = 0; i < (int)nums.size(); i++) {
                int complement = target - nums[i];
                if (seen.count(complement)) {
                    return {seen[complement], i};
                }
                seen[nums[i]] = i;  // Remember
            }
            return {-1, -1};
        }
    };
    
    // Visited set for graph traversal
    class GraphTraversal {
        unordered_set<int> visited;
        
        void dfs(int node, const vector<vector<int>>& graph) {
            if (visited.count(node)) return;
            visited.insert(node);  // Remember we've been here
            for (int neighbor : graph[node]) {
                dfs(neighbor, graph);
            }
        }
    };
    
    // DP table - remembering subproblem solutions
    class Fibonacci {
        unordered_map<int, long long> memo;
    public:
        long long fib(int n) {
            if (n <= 1) return n;
            if (memo.count(n)) return memo[n];  // Already computed
            return memo[n] = fib(n - 1) + fib(n - 2);  // Compute and remember
        }
    };
    
    // 2D DP table
    class LCS {
        vector<vector<int>> dp;
    public:
        int longestCommonSubsequence(const string& s1, const string& s2) {
            int m = s1.size(), n = s2.size();
            dp.assign(m + 1, vector<int>(n + 1, 0));
            
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[m][n];
        }
    };
    
    // Bitmask state compression
    class TSP {
        vector<vector<int>> dp;
        
        int solve(int mask, int pos, const vector<vector<int>>& dist) {
            int n = dist.size();
            if (mask == (1 << n) - 1) return dist[pos][0];  // Return to start
            if (dp[mask][pos] != -1) return dp[mask][pos];
            
            int result = INT_MAX;
            for (int city = 0; city < n; city++) {
                if (!(mask & (1 << city))) {
                    result = min(result, dist[pos][city] + 
                                solve(mask | (1 << city), city, dist));
                }
            }
            return dp[mask][pos] = result;
        }
    };
    
    // Rolling cache (space-optimized remembering)
    long long fibOptimized(int n) {
        if (n <= 1) return n;
        long long prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            long long curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P5. FORGET - Strategic State Pruning
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: discard irrelevant state
 * Hidden use: Sliding window shrink, greedy discard
 * Why fundamental: Optimal algorithms delete aggressively
 */

namespace P5_Forget {
    
    // Sliding window - forget elements outside the window
    int maxSumSubarray(const vector<int>& arr, int k) {
        if ((int)arr.size() < k) return -1;
        
        int windowSum = 0;
        for (int i = 0; i < k; i++) windowSum += arr[i];
        
        int maxSum = windowSum;
        for (int i = k; i < (int)arr.size(); i++) {
            windowSum += arr[i];     // Add new
            windowSum -= arr[i - k]; // FORGET old
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
    
    // LRU Cache - forget least recently used
    class LRUCache {
        int capacity;
        list<pair<int, int>> items;  // {key, value}
        unordered_map<int, list<pair<int, int>>::iterator> cache;
        
    public:
        LRUCache(int cap) : capacity(cap) {}
        
        int get(int key) {
            if (!cache.count(key)) return -1;
            // Move to front (most recently used)
            items.splice(items.begin(), items, cache[key]);
            return cache[key]->second;
        }
        
        void put(int key, int value) {
            if (cache.count(key)) {
                cache[key]->second = value;
                items.splice(items.begin(), items, cache[key]);
            } else {
                if ((int)items.size() >= capacity) {
                    // FORGET least recently used
                    cache.erase(items.back().first);
                    items.pop_back();
                }
                items.push_front({key, value});
                cache[key] = items.begin();
            }
        }
    };
    
    // Monotonic stack - forget irrelevant elements
    vector<int> nextGreaterElement(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> stk;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] < arr[i]) {
                result[stk.top()] = arr[i];
                stk.pop();  // FORGET - these elements are no longer relevant
            }
            stk.push(i);
        }
        return result;
    }
    
    // Greedy discard - keep only what's needed
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        vector<bool> inStack(26, false);
        
        for (int i = 0; i < (int)s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        string result;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (inStack[c]) continue;
            
            while (!result.empty() && result.back() > s[i] 
                   && lastIndex[result.back() - 'a'] > i) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();  // FORGET - we can get this char later
            }
            result += s[i];
            inStack[c] = true;
        }
        return result;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P6. REWIND - Backtracking and Rollback
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: backtrack / rollback
 * Hidden use: DFS, recursion, undo moves
 * Why fundamental: Search requires reversible execution
 */

namespace P6_Rewind {
    
    // Classic backtracking - permutations
    void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == (int)nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);      // Choose
            permute(nums, start + 1, result); // Explore
            swap(nums[start], nums[i]);      // REWIND - undo the choice
        }
    }
    
    // Subsets with backtracking
    void subsets(vector<int>& nums, int idx, vector<int>& current, 
                 vector<vector<int>>& result) {
        result.push_back(current);
        for (int i = idx; i < (int)nums.size(); i++) {
            current.push_back(nums[i]);       // Choose
            subsets(nums, i + 1, current, result);  // Explore
            current.pop_back();               // REWIND
        }
    }
    
    // N-Queens with rewind
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        // Check diagonals
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }
    
    void solveNQueens(int row, int n, vector<string>& board, 
                      vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';           // Place queen
                solveNQueens(row + 1, n, board, result);
                board[row][col] = '.';           // REWIND - remove queen
            }
        }
    }
    
    // Sudoku validation helper (must be declared before solveSudoku)
    bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
                return false;
        }
        return true;
    }
    
    // Sudoku solver with rewind
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValidSudoku(board, i, j, c)) {
                            board[i][j] = c;     // Try
                            if (solveSudoku(board)) return true;
                            board[i][j] = '.';   // REWIND
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P7. COMPRESS - Dimensionality Reduction
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: reduce dimensionality
 * Hidden use: State compression, bitmask, greedy invariant
 * Why fundamental: Complexity reduction is compression
 */

namespace P7_Compress {
    
    // Coordinate compression
    vector<int> compress(vector<int> arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        unordered_map<int, int> mapping;
        for (int i = 0; i < (int)sorted.size(); i++) {
            mapping[sorted[i]] = i;
        }
        
        for (int& x : arr) x = mapping[x];
        return arr;
    }
    
    // Bitmask state compression
    // Instead of vector<bool> visited(n), use int mask
    // visited[i] = true  →  mask |= (1 << i)
    // visited[i] check   →  mask & (1 << i)
    
    int countSetBits(int mask) {
        int count = 0;
        while (mask) {
            count += mask & 1;
            mask >>= 1;
        }
        return count;
    }
    
    // String hashing - compress string to integer
    class StringHash {
        static const long long BASE = 31;
        static const long long MOD = 1e9 + 7;
        
    public:
        long long hash(const string& s) {
            long long h = 0, pow = 1;
            for (char c : s) {
                h = (h + (c - 'a' + 1) * pow) % MOD;
                pow = (pow * BASE) % MOD;
            }
            return h;
        }
    };
    
    // Run-length encoding
    string runLengthEncode(const string& s) {
        if (s.empty()) return "";
        string result;
        int count = 1;
        for (int i = 1; i <= (int)s.size(); i++) {
            if (i < (int)s.size() && s[i] == s[i-1]) {
                count++;
            } else {
                result += s[i-1];
                if (count > 1) result += to_string(count);
                count = 1;
            }
        }
        return result;
    }
    
    // Matrix compression for DP
    // 2D DP: dp[i][j] often only needs dp[i-1][j] → compress to 1D
    int knapsack1D(const vector<int>& weights, const vector<int>& values, int W) {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < (int)weights.size(); i++) {
            for (int w = W; w >= weights[i]; w--) {  // Reverse to avoid overwrite
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
        return dp[W];
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P8. EXPAND - Generate Neighbors
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: generate neighbors
 * Hidden use: BFS, DFS, transitions
 * Why fundamental: Problems define spaces; solutions traverse them
 */

namespace P8_Expand {
    
    // 4-directional grid expansion
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    
    vector<pair<int, int>> getNeighbors4(int x, int y, int rows, int cols) {
        vector<pair<int, int>> neighbors;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                neighbors.push_back({nx, ny});
            }
        }
        return neighbors;
    }
    
    // 8-directional grid expansion
    const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    vector<pair<int, int>> getNeighbors8(int x, int y, int rows, int cols) {
        vector<pair<int, int>> neighbors;
        for (int d = 0; d < 8; d++) {
            int nx = x + dx8[d], ny = y + dy8[d];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                neighbors.push_back({nx, ny});
            }
        }
        return neighbors;
    }
    
    // Graph neighbor expansion
    vector<int> getGraphNeighbors(int node, const vector<vector<int>>& graph) {
        return graph[node];
    }
    
    // State expansion (BFS on states)
    // Example: Open lock problem - each state expands to 8 neighbors
    vector<string> expandLockState(const string& state) {
        vector<string> neighbors;
        for (int i = 0; i < 4; i++) {
            string next = state;
            // Increment digit
            next[i] = (state[i] - '0' + 1) % 10 + '0';
            neighbors.push_back(next);
            // Decrement digit
            next[i] = (state[i] - '0' + 9) % 10 + '0';
            neighbors.push_back(next);
        }
        return neighbors;
    }
    
    // Knight moves on chess board
    const int knightDx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int knightDy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    vector<pair<int, int>> knightMoves(int x, int y, int n) {
        vector<pair<int, int>> moves;
        for (int d = 0; d < 8; d++) {
            int nx = x + knightDx[d], ny = y + knightDy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                moves.push_back({nx, ny});
            }
        }
        return moves;
    }
    
    // Word ladder - expand by changing one letter
    vector<string> expandWord(const string& word, const unordered_set<string>& dict) {
        vector<string> neighbors;
        for (int i = 0; i < (int)word.size(); i++) {
            string next = word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != word[i]) {
                    next[i] = c;
                    if (dict.count(next)) neighbors.push_back(next);
                }
            }
        }
        return neighbors;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// P9. APPROXIMATE - Estimation and Bounding
// ═══════════════════════════════════════════════════════════════════════════
/**
 * What it is: estimate, bound, monotonicity
 * Hidden use: Binary search on answer, greedy proofs
 * Why fundamental: Exact search is often impossible
 */

namespace P9_Approximate {
    
    // Binary search on answer - approximate the solution
    // "What's the minimum capacity to ship in D days?"
    bool canShip(const vector<int>& weights, int capacity, int days) {
        int currentLoad = 0, daysNeeded = 1;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                daysNeeded++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        return daysNeeded <= days;
    }
    
    int shipWithinDays(const vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShip(weights, mid, days)) {
                hi = mid;  // This works, try smaller
            } else {
                lo = mid + 1;  // Too small, need larger
            }
        }
        return lo;
    }
    
    // Floating point binary search - continuous approximation
    double squareRoot(double x, double epsilon = 1e-9) {
        double lo = 0, hi = max(1.0, x);
        while (hi - lo > epsilon) {
            double mid = lo + (hi - lo) / 2;
            if (mid * mid < x) lo = mid;
            else hi = mid;
        }
        return lo + (hi - lo) / 2;
    }
    
    // Newton-Raphson approximation
    double sqrtNewton(double x, double epsilon = 1e-9) {
        if (x < 0) return -1;
        if (x == 0) return 0;
        double guess = x;
        while (abs(guess * guess - x) > epsilon) {
            guess = (guess + x / guess) / 2;
        }
        return guess;
    }
    
    // Probabilistic approximation - Monte Carlo
    double estimatePi(int samples) {
        int inside = 0;
        srand(42);
        for (int i = 0; i < samples; i++) {
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;
            if (x * x + y * y <= 1) inside++;
        }
        return 4.0 * inside / samples;
    }
    
    // Lower bound / Upper bound usage
    // "Find first position where can achieve target"
    int lowerBound(const vector<int>& arr, int target) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    
    // Ternary search for unimodal function maximum
    double ternarySearchMax(function<double(double)> f, double lo, double hi, 
                            double epsilon = 1e-9) {
        while (hi - lo > epsilon) {
            double mid1 = lo + (hi - lo) / 3;
            double mid2 = hi - (hi - lo) / 3;
            if (f(mid1) < f(mid2)) lo = mid1;
            else hi = mid2;
        }
        return lo + (hi - lo) / 2;
    }
}

// ═══════════════════════════════════════════════════════════════════════════
// DEMO AND EXAMPLES
// ═══════════════════════════════════════════════════════════════════════════

int main() {
    cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║          PRIMITIVE OPERATIONS DEMONSTRATION                  ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";
    
    // P0: Compare
    cout << "P0. COMPARE\n";
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    auto [minVal, maxVal] = P0_Compare::findMinMax(arr);
    cout << "   Min: " << minVal << ", Max: " << maxVal << "\n\n";
    
    // P1: Accumulate
    cout << "P1. ACCUMULATE\n";
    P1_Accumulate::PrefixSum ps(arr);
    cout << "   Sum of range [2, 5]: " << ps.query(2, 5) << "\n\n";
    
    // P4: Remember (Fibonacci)
    cout << "P4. REMEMBER (Memoization)\n";
    cout << "   Fibonacci(40): " << P4_Remember::fibOptimized(40) << "\n\n";
    
    // P7: Compress
    cout << "P7. COMPRESS\n";
    string s = "aaabbbcccaaa";
    cout << "   RLE of '" << s << "': " << P7_Compress::runLengthEncode(s) << "\n\n";
    
    // P9: Approximate
    cout << "P9. APPROXIMATE\n";
    cout << "   sqrt(2) ≈ " << fixed << setprecision(10) 
         << P9_Approximate::sqrtNewton(2) << "\n";
    cout << "   π (Monte Carlo, 1M samples) ≈ " 
         << P9_Approximate::estimatePi(1000000) << "\n\n";
    
    cout << "═══════════════════════════════════════════════════════════════\n";
    cout << "All 10 primitives form the COMPLETE basis for algorithm design!\n";
    
    return 0;
}
