// ──────────────────────────────────────────────────
// Problem  : 887. Super Egg Drop
// Difficulty: Hard
// Tags     : Math, Binary Search, Dynamic Programming
// Link     : https://leetcode.com/problems/super-egg-drop/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8124000 (beats 91%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1, 0);
        int m = 0;
        while (dp[k] < n) {
            m++;
            for (int i = k; i >= 1; --i) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        return m;
    }
};