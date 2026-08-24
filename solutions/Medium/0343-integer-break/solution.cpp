// ──────────────────────────────────────────────────
// Problem  : 343. Integer Break
// Difficulty: Medium
// Tags     : Math, Dynamic Programming
// Link     : https://leetcode.com/problems/integer-break/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7952000 (beats 69%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};