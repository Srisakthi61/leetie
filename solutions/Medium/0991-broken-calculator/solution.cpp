// ──────────────────────────────────────────────────
// Problem  : 991. Broken Calculator
// Difficulty: Medium
// Tags     : Math, Greedy
// Link     : https://leetcode.com/problems/broken-calculator/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7852000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue) {
            if (target % 2 == 1) {
                target++;
            } else {
                target /= 2;
            }
            ans++;
        }
        return ans + (startValue - target);
    }
};