// ──────────────────────────────────────────────────
// Problem  : 174. Dungeon Game
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Matrix
// Link     : https://leetcode.com/problems/dungeon-game/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10124000 (beats 7%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int m = dungeonSize;
    int n = dungeonColSize[0];

    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 1e9;
        }
    }

    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int minHealthNeeded = MIN(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = MAX(1, minHealthNeeded - dungeon[i][j]);
        }
    }

    int result = dp[0][0];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}