// ──────────────────────────────────────────────────
// Problem  : 633. Sum of Square Numbers
// Difficulty: Medium
// Tags     : Math, Two Pointers, Binary Search
// Link     : https://leetcode.com/problems/sum-of-square-numbers/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7876000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c);
        while (left <= right) {
            long long sum = left * left + right * right;
            if (sum == c) return true;
            else if (sum < c) left++;
            else right--;
        }
        return false;
    }
};