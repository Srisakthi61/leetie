// ──────────────────────────────────────────────────
// Problem  : 462. Minimum Moves to Equal Array Elements II
// Difficulty: Medium
// Tags     : Array, Math, Sorting
// Link     : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 15808000 (beats 14%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int moves = 0;
        
        for (int num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};