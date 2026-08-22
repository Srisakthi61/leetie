// ──────────────────────────────────────────────────
// Problem  : 467. Unique Substrings in Wraparound String
// Difficulty: Medium
// Tags     : String, Dynamic Programming
// Link     : https://leetcode.com/problems/unique-substrings-in-wraparound-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10996000 (beats 27%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> count(26, 0);
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)) {
                maxLength++;
            } else {
                maxLength = 1;
            }
            int index = s[i] - 'a';
            count[index] = max(count[index], maxLength);
        }
        
        int sum = 0;
        for (int c : count) {
            sum += c;
        }
        
        return sum;
    }
};