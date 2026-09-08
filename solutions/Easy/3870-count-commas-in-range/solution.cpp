// ──────────────────────────────────────────────────
// Problem  : 3870. Count Commas in Range
// Difficulty: Easy
// Tags     : Math
// Link     : https://leetcode.com/problems/count-commas-in-range/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8492000 (beats 84%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        return n - 999;
    }
};