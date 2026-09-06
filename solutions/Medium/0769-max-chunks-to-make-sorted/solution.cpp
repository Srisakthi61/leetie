// ──────────────────────────────────────────────────
// Problem  : 769. Max Chunks To Make Sorted
// Difficulty: Medium
// Tags     : Array, Stack, Greedy, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/max-chunks-to-make-sorted/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8160000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int max_val = 0;
        for (int i = 0; i < arr.size(); ++i) {
            max_val = max(max_val, arr[i]);
            if (max_val == i) {
                chunks++;
            }
        }
        return chunks;
    }
};