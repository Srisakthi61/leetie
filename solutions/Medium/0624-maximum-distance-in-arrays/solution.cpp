// ──────────────────────────────────────────────────
// Problem  : 624. Maximum Distance in Arrays
// Difficulty: Medium
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/maximum-distance-in-arrays/
// Runtime  : 3 ms (beats 35%)
// Memory   : 108140000 (beats 42%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0].front();
        int max_val = arrays[0].back();
        int max_dist = 0;

        for (size_t i = 1; i < arrays.size(); ++i) {
            max_dist = max(max_dist, max(abs(arrays[i].back() - min_val), abs(max_val - arrays[i].front())));
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }

        return max_dist;
    }
};