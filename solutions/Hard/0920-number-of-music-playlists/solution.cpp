// ──────────────────────────────────────────────────
// Problem  : 920. Number of Music Playlists
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Combinatorics
// Link     : https://leetcode.com/problems/number-of-music-playlists/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7836000 (beats 95%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long long dp[101][101] = {0};
        long long MOD = 1e9 + 7;
        dp[0][0] = 1;

        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % MOD;
                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }

        return dp[goal][n];
    }
};