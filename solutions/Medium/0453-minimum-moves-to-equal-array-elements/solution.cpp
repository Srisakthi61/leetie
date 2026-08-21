// ──────────────────────────────────────────────────
// Problem  : 453. Minimum Moves to Equal Array Elements
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8080000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        for (int num : nums) {
            min_val = min(min_val, num);
        }
        
        int moves = 0;
        for (int num : nums) {
            moves += num - min_val;
        }
        
        return moves;
    }
};