// ──────────────────────────────────────────────────
// Problem  : 922. Sort Array By Parity II
// Difficulty: Easy
// Tags     : Array, Two Pointers, Sorting
// Link     : https://leetcode.com/problems/sort-array-by-parity-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 25712000 (beats 96%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        while (i < n && j < n) {
            while (i < n && nums[i] % 2 == 0) {
                i += 2;
            }
            while (j < n && nums[j] % 2 != 0) {
                j += 2;
            }
            if (i < n && j < n) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};