// ──────────────────────────────────────────────────
// Problem  : 312. Burst Balloons
// Difficulty: Hard
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/burst-balloons/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8436000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxCoins(int* nums, int numsSize) {
    int arr[numsSize + 2];
    arr[0] = 1;
    arr[numsSize + 1] = 1;
    for (int i = 0; i < numsSize; i++) {
        arr[i + 1] = nums[i];
    }

    int n = numsSize + 2;
    int dp[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int len = 2; len < n; len++) {
        for (int left = 0; left < n - len; left++) {
            int right = left + len;
            for (int k = left + 1; k < right; k++) {
                int coins = arr[left] * arr[k] * arr[right] + dp[left][k] + dp[k][right];
                if (coins > dp[left][right]) {
                    dp[left][right] = coins;
                }
            }
        }
    }

    return dp[0][n - 1];
}