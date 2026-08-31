// ──────────────────────────────────────────────────
// Problem  : 829. Consecutive Numbers Sum
// Difficulty: Hard
// Tags     : Math, Enumeration
// Link     : https://leetcode.com/problems/consecutive-numbers-sum/
// Runtime  : 2 ms (beats 52%)
// Memory   : 7840000 (beats 69%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int k = 1; k * (k - 1) < 2 * n; ++k) {
            int numerator = n - (k * (k - 1)) / 2;
            if (numerator % k == 0) {
                count++;
            }
        }
        return count;
    }
};