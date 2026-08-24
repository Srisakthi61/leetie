// ──────────────────────────────────────────────────
// Problem  : 470. Implement Rand10() Using Rand7()
// Difficulty: Medium
// Tags     : Math, Rejection Sampling, Randomized, Probability and Statistics
// Link     : https://leetcode.com/problems/implement-rand10-using-rand7/
// Runtime  : 6 ms (beats 58%)
// Memory   : 10764000 (beats 94%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int rand10() {
        int idx;
        do {
            int row = rand7();
            int col = rand7();
            idx = (row - 1) * 7 + col;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};