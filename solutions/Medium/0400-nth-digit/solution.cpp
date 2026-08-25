// ──────────────────────────────────────────────────
// Problem  : 400. Nth Digit
// Difficulty: Medium
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/nth-digit/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7956000 (beats 34%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;
        long long count = 9;
        long long start = 1;

        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }
};