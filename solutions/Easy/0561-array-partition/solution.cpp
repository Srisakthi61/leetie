// ──────────────────────────────────────────────────
// Problem  : 561. Array Partition
// Difficulty: Easy
// Tags     : Array, Greedy, Sorting, Counting Sort
// Link     : https://leetcode.com/problems/array-partition/
// Runtime  : 15 ms (beats 33%)
// Memory   : 32164000 (beats 22%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};