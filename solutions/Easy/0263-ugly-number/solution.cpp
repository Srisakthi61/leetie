// ──────────────────────────────────────────────────
// Problem  : 263. Ugly Number
// Difficulty: Easy
// Tags     : Math
// Link     : https://leetcode.com/problems/ugly-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7764000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (int p : {2, 3, 5}) {
            while (n % p == 0) {
                n /= p;
            }
        }
        return n == 1;
    }
};