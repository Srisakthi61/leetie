// ──────────────────────────────────────────────────
// Problem  : 905. Sort Array By Parity
// Difficulty: Easy
// Tags     : Array, Two Pointers, Sorting
// Link     : https://leetcode.com/problems/sort-array-by-parity/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8312000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }
            if (nums[left] % 2 == 0) left++;
            if (nums[right] % 2 != 0) right--;
        }
        return nums;
    }
};