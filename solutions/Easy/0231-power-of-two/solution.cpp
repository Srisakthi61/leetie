// ──────────────────────────────────────────────────
// Problem  : 231. Power of Two
// Difficulty: Easy
// Tags     : Math, Bit Manipulation, Recursion
// Link     : https://leetcode.com/problems/power-of-two/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7796000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public:
        bool isPowerOfTwo(int n) {
                return n > 0 && (n & (n - 1)) == 0;
                    }
                    };
