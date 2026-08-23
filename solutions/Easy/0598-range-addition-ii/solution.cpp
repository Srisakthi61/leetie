// ──────────────────────────────────────────────────
// Problem  : 598. Range Addition II
// Difficulty: Easy
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/range-addition-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8644000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m = m;
        int min_n = n;
        for (const auto& op : ops) {
            min_m = min(min_m, op[0]);
            min_n = min(min_n, op[1]);
        }
        return min_m * min_n;
    }
};