// ──────────────────────────────────────────────────
// Problem  : 258. Add Digits
// Difficulty: Easy
// Tags     : Math, Simulation, Number Theory
// Link     : https://leetcode.com/problems/add-digits/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8512000 (beats 80%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};