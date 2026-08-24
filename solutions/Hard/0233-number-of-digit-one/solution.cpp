// ──────────────────────────────────────────────────
// Problem  : 233. Number of Digit One
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Recursion
// Link     : https://leetcode.com/problems/number-of-digit-one/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7860000 (beats 54%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        long long factor = 1;
        while (factor <= n) {
            long long divider = factor * 10;
            count += (n / divider) * factor + min(max(n % divider - factor + 1, 0LL), factor);
            factor = divider;
        }
        return count;
    }
};