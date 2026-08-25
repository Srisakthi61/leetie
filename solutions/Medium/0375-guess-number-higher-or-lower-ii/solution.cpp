// ──────────────────────────────────────────────────
// Problem  : 375. Guess Number Higher or Lower II
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Minimax, Game Theory
// Link     : https://leetcode.com/problems/guess-number-higher-or-lower-ii/
// Runtime  : 40 ms (beats 62%)
// Memory   : 11088000 (beats 56%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int cost = k + max(dp[i][k - 1], dp[k + 1][j]);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n];
    }
};