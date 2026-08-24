// ──────────────────────────────────────────────────
// Problem  : 371. Sum of Two Integers
// Difficulty: Medium
// Tags     : Math, Bit Manipulation
// Link     : https://leetcode.com/problems/sum-of-two-integers/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7732000 (beats 67%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};