/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║  SLIDING WINDOW: Minimum Window Substring                                 ║
 * ║  LeetCode 76 | Difficulty: Hard                                           ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🎯 PATTERN RECOGNITION CUES                                             │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ ✓ "Minimum window containing all characters of T"                       │
 * │ ✓ Finding SHORTEST substring satisfying constraint                      │
 * │ ✓ Constraint: must contain ALL characters (with frequency)              │
 * │ ✓ Key insight: expand until valid, then shrink while still valid       │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🧠 BRAIN TRAINING                                                       │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ MINIMUM WINDOW TEMPLATE:                                                │
 * │   1. Expand right until window is VALID                                 │
 * │   2. While VALID: record answer, then shrink from left                  │
 * │   3. Continue until right reaches end                                   │
 * │                                                                         │
 * │ vs MAXIMUM WINDOW TEMPLATE:                                             │
 * │   1. Expand right                                                       │
 * │   2. While INVALID: shrink from left                                    │
 * │   3. Record answer (window is now valid)                                │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * Time: O(m + n) | Space: O(m) where m = |t|, n = |s|
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || s.size() < t.size()) return "";
        
        // Step 1: Build frequency map of target
        unordered_map<char, int> need, have;
        for (char c : t) need[c]++;
        
        int required = need.size();  // Unique chars needed
        int formed = 0;              // Unique chars with enough count
        
        int left = 0;
        int minLen = INT_MAX, minStart = 0;
        
        // Step 2: Expand window with right pointer
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            have[c]++;
            
            // Check if current char count satisfies requirement
            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }
            
            // Step 3: Contract window while valid (find minimum)
            while (formed == required) {
                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Shrink from left
                char leftChar = s[left];
                have[leftChar]--;
                if (need.count(leftChar) && have[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

/*
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🔑 KEY INSIGHT: "formed" counter optimization                           │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ Instead of comparing entire hash maps every iteration O(m),             │
 * │ track how many UNIQUE chars are satisfied → O(1) check                  │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * RELATED PROBLEMS:
 * - LC 438: Find All Anagrams (fixed window, exact match)
 * - LC 567: Permutation in String (fixed window, exact match)
 * - LC 30: Substring with Concatenation (word-level window)
 */

int main() {
    Solution sol;
    
    cout << "Pattern: SLIDING WINDOW (Variable Size - Minimum)\n";
    cout << "=================================================\n\n";
    
    cout << "s=\"ADOBECODEBANC\", t=\"ABC\"\n";
    cout << "Output: \"" << sol.minWindow("ADOBECODEBANC", "ABC") << "\"\n\n";
    
    cout << "s=\"a\", t=\"a\"\n";
    cout << "Output: \"" << sol.minWindow("a", "a") << "\"\n\n";
    
    cout << "s=\"a\", t=\"aa\"\n";
    cout << "Output: \"" << sol.minWindow("a", "aa") << "\"\n";
    
    return 0;
}
