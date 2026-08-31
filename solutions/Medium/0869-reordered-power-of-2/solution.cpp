// ──────────────────────────────────────────────────
// Problem  : 869. Reordered Power of 2
// Difficulty: Medium
// Tags     : Hash Table, Math, Sorting, Counting, Enumeration
// Link     : https://leetcode.com/problems/reordered-power-of-2/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8864000 (beats 64%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 31; ++i) {
            string p = to_string(1 << i);
            sort(p.begin(), p.end());
            if (s == p) {
                return true;
            }
        }
        return false;
    }
};