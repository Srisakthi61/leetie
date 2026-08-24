// ──────────────────────────────────────────────────
// Problem  : 326. Power of Three
// Difficulty: Easy
// Tags     : Math, Recursion
// Link     : https://leetcode.com/problems/power-of-three/
// Runtime  : 11 ms (beats 6%)
// Memory   : 8788000 (beats 98%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};