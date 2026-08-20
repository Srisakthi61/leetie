// ──────────────────────────────────────────────────
// Problem  : 238. Product of Array Except Self
// Difficulty: Medium
// Tags     : Array, Prefix Sum
// Link     : https://leetcode.com/problems/product-of-array-except-self/
// Runtime  : 2 ms (beats 94%)
// Memory   : 72192000 (beats 29%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];

        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
}