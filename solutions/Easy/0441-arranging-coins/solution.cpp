// ──────────────────────────────────────────────────
// Problem  : 441. Arranging Coins
// Difficulty: Easy
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/arranging-coins/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8776000 (beats 68%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n;
        long long ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long curr = mid * (mid + 1) / 2;
            if (curr <= n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};