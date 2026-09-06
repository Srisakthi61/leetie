// ──────────────────────────────────────────────────
// Problem  : 1051. Height Checker
// Difficulty: Easy
// Tags     : Array, Sorting, Counting Sort, Bubble Sort
// Link     : https://leetcode.com/problems/height-checker/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11492000 (beats 32%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }
        return count;
    }
};