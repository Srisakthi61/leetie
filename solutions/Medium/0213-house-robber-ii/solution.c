// ──────────────────────────────────────────────────
// Problem  : 213. House Robber II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/house-robber-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8668000 (beats 94%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int robLinear(int* nums, int start, int end) {
    int prev1 = 0;
    int prev2 = 0;

    for (int i = start; i <= end; i++) {
        int temp = prev1;
        prev1 = MAX(prev1, prev2 + nums[i]);
        prev2 = temp;
    }

    return prev1;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }

    int option1 = robLinear(nums, 0, numsSize - 2);
    int option2 = robLinear(nums, 1, numsSize - 1);

    return MAX(option1, option2);
}