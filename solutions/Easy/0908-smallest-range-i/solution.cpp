// ──────────────────────────────────────────────────
// Problem  : 908. Smallest Range I
// Difficulty: Easy
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/smallest-range-i/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8304000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = nums[0], max_val = nums[0];
        for (int x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }
        return max(0, max_val - min_val - 2 * k);
    }
};