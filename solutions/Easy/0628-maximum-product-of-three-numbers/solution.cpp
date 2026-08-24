// ──────────────────────────────────────────────────
// Problem  : 628. Maximum Product of Three Numbers
// Difficulty: Easy
// Tags     : Array, Math, Sorting
// Link     : https://leetcode.com/problems/maximum-product-of-three-numbers/
// Runtime  : 22 ms (beats 9%)
// Memory   : 31600000 (beats 49%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};