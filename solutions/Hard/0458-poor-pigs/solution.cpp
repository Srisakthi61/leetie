// ──────────────────────────────────────────────────
// Problem  : 458. Poor Pigs
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Combinatorics
// Link     : https://leetcode.com/problems/poor-pigs/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7936000 (beats 31%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int states = minutesToTest / minutesToDie + 1;
        while (pow(states, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};