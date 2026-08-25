// ──────────────────────────────────────────────────
// Problem  : 667. Beautiful Arrangement II
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/beautiful-arrangement-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7984000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l = 1, r = n;
        while (l <= r) {
            if (k > 1) {
                res.push_back(k % 2 != 0 ? l++ : r--);
                k--;
            } else {
                res.push_back(l++);
            }
        }
        return res;
    }
};