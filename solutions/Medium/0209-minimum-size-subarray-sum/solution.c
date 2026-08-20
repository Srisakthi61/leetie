// ──────────────────────────────────────────────────
// Problem  : 209. Minimum Size Subarray Sum
// Difficulty: Medium
// Tags     : Array, Binary Search, Sliding Window, Prefix Sum
// Link     : https://leetcode.com/problems/minimum-size-subarray-sum/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8436000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int currentSum = 0;
    int minLength = numsSize + 1;

    for (int right = 0; right < numsSize; right++) {
        currentSum += nums[right];

        while (currentSum >= target) {
            int currentLength = right - left + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            currentSum -= nums[left];
            left++;
        }
    }

    return (minLength == numsSize + 1) ? 0 : minLength;
}