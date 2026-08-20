// ──────────────────────────────────────────────────
// Problem  : 300. Longest Increasing Subsequence
// Difficulty: Medium
// Tags     : Array, Binary Search, Dynamic Programming, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/longest-increasing-subsequence/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9028000 (beats 71%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int tails[numsSize];
    int len = 0;

    for (int i = 0; i < numsSize; i++) {
        int left = 0, right = len;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < nums[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        tails[left] = nums[i];
        if (left == len) {
            len++;
        }
    }

    return len;
}