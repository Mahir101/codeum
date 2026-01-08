/**
 * ╔═══════════════════════════════════════════════════════════════════════════╗
 * ║  SLIDING WINDOW: Longest Substring Without Repeating Characters          ║
 * ║  LeetCode 3 | Difficulty: Medium                                          ║
 * ╚═══════════════════════════════════════════════════════════════════════════╝
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🎯 PATTERN RECOGNITION CUES                                             │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ ✓ Keywords: "substring", "contiguous", "longest/shortest"               │
 * │ ✓ Looking for optimal window satisfying some constraint                 │
 * │ ✓ Constraint involves uniqueness, frequency, or sum                     │
 * │ ✓ Brute force would be O(n²) or O(n³) - sliding window reduces to O(n) │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 🧠 BRAIN TRAINING: How to internalize this pattern                      │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ 1. Visualize a "view window" sliding across the array                   │
 * │ 2. Ask: "What makes my window INVALID?"                                 │
 * │ 3. Ask: "How do I SHRINK to make it valid again?"                       │
 * │ 4. Practice: Start with fixed window, then variable window              │
 * │ 5. Key insight: Right pointer ALWAYS moves; left moves to restore valid │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 📊 COMPLEXITY                                                           │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ Time: O(n) - each element visited at most twice (once by each pointer) │
 * │ Space: O(min(m, n)) where m = charset size                              │
 * └─────────────────────────────────────────────────────────────────────────┘
 * 
 * SIMILAR PROBLEMS: LC 159, LC 340, LC 424, LC 1004
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * APPROACH: Variable-size sliding window with hash map
     * 
     * ATTACK STRATEGY:
     * 1. Expand window by moving right pointer
     * 2. Track character positions in hash map
     * 3. When duplicate found: shrink window by moving left past duplicate
     * 4. Update max length at each step
     */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;  // char -> last seen index
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            
            // If char was seen and is within current window, shrink
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;  // Move left past the duplicate
            }
            
            lastSeen[c] = right;  // Update last seen position
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    /**
     * VARIATION 1: Using frequency array (when charset is known)
     * Slightly faster due to array access vs hash map
     */
    int lengthOfLongestSubstringArray(string s) {
        int freq[128] = {0};  // ASCII charset
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < (int)s.size(); right++) {
            freq[s[right]]++;
            
            // Shrink while we have duplicates
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

/*
 * ┌─────────────────────────────────────────────────────────────────────────┐
 * │ 📝 PRACTICE EXERCISES                                                   │
 * ├─────────────────────────────────────────────────────────────────────────┤
 * │ 1. Solve with pencil & paper first - draw the window movement          │
 * │ 2. Trace through "abcabcbb" step by step                               │
 * │ 3. Try edge cases: "", "a", "aaaaaa", "abcdef"                         │
 * │ 4. Modify to return the actual substring, not just length              │
 * │ 5. Extend to "at most K distinct characters" (LC 340)                  │
 * └─────────────────────────────────────────────────────────────────────────┘
 */

int main() {
    Solution sol;
    
    // Test cases
    cout << "Pattern: SLIDING WINDOW (Variable Size - Maximum)\n";
    cout << "================================================\n\n";
    
    vector<string> tests = {"abcabcbb", "bbbbb", "pwwkew", "", "a", "abcdef"};
    for (const string& s : tests) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << sol.lengthOfLongestSubstring(s) << "\n\n";
    }
    
    return 0;
}
