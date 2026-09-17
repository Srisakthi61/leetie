// ──────────────────────────────────────────────────
// Problem  : 1. Two Sum
// Difficulty: Easy
// Tags     : Array, Hash Table
// Link     : https://leetcode.com/problems/two-sum/
// Runtime  : 36 ms (beats 43%)
// Memory   : 47024000 (beats 59%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int[] arr=new int[2];
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    arr[0]=i;
                    arr[1]=j;
                    break;
                }
            }
        }
        return arr; // No solution found
    }
}