// ──────────────────────────────────────────────────
// Problem  : 1006. Clumsy Factorial
// Difficulty: Medium
// Tags     : Math, Stack, Simulation
// Link     : https://leetcode.com/problems/clumsy-factorial/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7836000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int clumsy(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
        if (n == 4) return 7;
        
        if (n % 4 == 1) return n + 2;
        if (n % 4 == 2) return n + 2;
        if (n % 4 == 3) return n - 1;
        return n + 1;
    }
};