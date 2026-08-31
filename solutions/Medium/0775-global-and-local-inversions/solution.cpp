// ──────────────────────────────────────────────────
// Problem  : 775. Global and Local Inversions
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/global-and-local-inversions/
// Runtime  : 1 ms (beats 33%)
// Memory   : 87036000 (beats 77%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};