// ──────────────────────────────────────────────────
// Problem  : 367. Valid Perfect Square
// Difficulty: Easy
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/valid-perfect-square/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7664000 (beats 89%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            if (sq == num) return true;
            else if (sq < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};