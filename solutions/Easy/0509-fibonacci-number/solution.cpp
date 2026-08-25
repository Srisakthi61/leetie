// ──────────────────────────────────────────────────
// Problem  : 509. Fibonacci Number
// Difficulty: Easy
// Tags     : Math, Dynamic Programming, Recursion, Memoization
// Link     : https://leetcode.com/problems/fibonacci-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7572000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};