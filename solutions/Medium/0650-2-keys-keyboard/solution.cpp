// ──────────────────────────────────────────────────
// Problem  : 650. 2 Keys Keyboard
// Difficulty: Medium
// Tags     : Math, Dynamic Programming
// Link     : https://leetcode.com/problems/2-keys-keyboard/
// Runtime  : 2 ms (beats 55%)
// Memory   : 7896000 (beats 79%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int d = 2; d * d <= n; ++d) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
        }
        if (n > 1) {
            ans += n;
        }
        return ans;
    }
};