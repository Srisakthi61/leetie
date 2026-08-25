// ──────────────────────────────────────────────────
// Problem  : 668. Kth Smallest Number in Multiplication Table
// Difficulty: Hard
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7752000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};