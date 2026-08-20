// ──────────────────────────────────────────────────
// Problem  : 309. Best Time to Buy and Sell Stock with Cooldown
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8444000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;
    }

    int hold = -prices[0];
    int sold = 0;
    int rest = 0;

    for (int i = 1; i < pricesSize; i++) {
        int prevHold = hold;
        int prevSold = sold;
        int prevRest = rest;

        hold = max(prevHold, prevRest - prices[i]);
        sold = prevHold + prices[i];
        rest = max(prevRest, prevSold);
    }

    return max(sold, rest);
}