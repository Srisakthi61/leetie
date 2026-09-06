// ──────────────────────────────────────────────────
// Problem  : 969. Pancake Sorting
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy, Sorting
// Link     : https://leetcode.com/problems/pancake-sorting/
// Runtime  : 0 ms (beats 100%)
// Memory   : 14212000 (beats 16%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int x = n; x > 0; --x) {
            auto it = find(arr.begin(), arr.begin() + x, x);
            int idx = distance(arr.begin(), it);
            if (idx == x - 1) continue;
            if (idx != 0) {
                res.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }
            res.push_back(x);
            reverse(arr.begin(), arr.begin() + x);
        }
        return res;
    }
};