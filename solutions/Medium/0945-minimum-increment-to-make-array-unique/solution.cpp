// ──────────────────────────────────────────────────
// Problem  : 945. Minimum Increment to Make Array Unique
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting, Counting
// Link     : https://leetcode.com/problems/minimum-increment-to-make-array-unique/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8260000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] - nums[i] + 1;
                nums[i] += increment;
                moves += increment;
            }
        }
        return moves;
    }
};