// ──────────────────────────────────────────────────
// Problem  : 1040. Moving Stones Until Consecutive II
// Difficulty: Medium
// Tags     : Array, Math, Sliding Window, Sorting
// Link     : https://leetcode.com/problems/moving-stones-until-consecutive-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 17112000 (beats 4%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        
        int max_moves = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);
        
        if (max_moves == 0) {
            return {0, 0};
        }
        
        int min_moves = n;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && stones[j] - stones[i] < n) {
                j++;
            }
            int already_placed = j - i;
            if (already_placed == n - 1 && stones[j - 1] - stones[i] == n - 2) {
                min_moves = min(min_moves, 2);
            } else {
                min_moves = min(min_moves, n - already_placed);
            }
        }
        
        return {min_moves, max_moves};
    }
};