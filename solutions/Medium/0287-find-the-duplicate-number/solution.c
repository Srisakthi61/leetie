// ──────────────────────────────────────────────────
// Problem  : 287. Find the Duplicate Number
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Bit Manipulation, Pigeonhole Principle, Floyd's Cycle Finding Algorithm
// Link     : https://leetcode.com/problems/find-the-duplicate-number/
// Runtime  : 5 ms (beats 38%)
// Memory   : 14892000 (beats 82%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}