// ──────────────────────────────────────────────────
// Problem  : 1033. Moving Stones Until Consecutive
// Difficulty: Medium
// Tags     : Math, Brainteaser
// Link     : https://leetcode.com/problems/moving-stones-until-consecutive/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8208000 (beats 59%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> pos = {a, b, c};
        sort(pos.begin(), pos.end());
        
        int x = pos[0], y = pos[1], z = pos[2];
        
        if (z - x == 2) {
            return {0, 0};
        }
        
        int min_moves = 2;
        if (y - x <= 2 || z - y <= 2) {
            min_moves = 1;
        }
        
        int max_moves = (y - x - 1) + (z - y - 1);
        
        return {min_moves, max_moves};
    }
};