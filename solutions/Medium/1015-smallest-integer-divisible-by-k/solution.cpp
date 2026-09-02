// ──────────────────────────────────────────────────
// Problem  : 1015. Smallest Integer Divisible by K
// Difficulty: Medium
// Tags     : Hash Table, Math, Pigeonhole Principle
// Link     : https://leetcode.com/problems/smallest-integer-divisible-by-k/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7752000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int remainder = 0;
        for (int length = 1; length <= k; ++length) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length;
            }
        }
        return -1;
    }
};