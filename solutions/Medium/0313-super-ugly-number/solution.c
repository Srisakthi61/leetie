// ──────────────────────────────────────────────────
// Problem  : 313. Super Ugly Number
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming
// Link     : https://leetcode.com/problems/super-ugly-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8428000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    long dp[n];
    dp[0] = 1;

    int indices[primesSize];
    for (int i = 0; i < primesSize; i++) {
        indices[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        long minNext = LONG_MAX;

        for (int j = 0; j < primesSize; j++) {
            long nextVal = dp[indices[j]] * (long)primes[j];
            if (nextVal < minNext) {
                minNext = nextVal;
            }
        }

        dp[i] = minNext;

        for (int j = 0; j < primesSize; j++) {
            if (dp[indices[j]] * (long)primes[j] == minNext) {
                indices[j]++;
            }
        }
    }

    return (int)dp[n - 1];
}