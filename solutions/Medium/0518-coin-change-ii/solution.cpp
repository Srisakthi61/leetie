// ──────────────────────────────────────────────────
// Problem  : 518. Coin Change II
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Knapsack Problem, Complete Knapsack
// Link     : https://leetcode.com/problems/coin-change-ii/
// Runtime  : 1 ms (beats 99%)
// Memory   : 10024000 (beats 97%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};