// ──────────────────────────────────────────────────
// Problem  : 779. K-th Symbol in Grammar
// Difficulty: Medium
// Tags     : Math, Bit Manipulation, Recursion
// Link     : https://leetcode.com/problems/k-th-symbol-in-grammar/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7780000 (beats 83%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int parent = kthGrammar(n - 1, (k + 1) / 2);
        if (k % 2 == 1) {
            return parent;
        } else {
            return 1 - parent;
        }
    }
};