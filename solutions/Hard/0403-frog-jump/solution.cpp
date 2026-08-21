// ──────────────────────────────────────────────────
// Problem  : 403. Frog Jump
// Difficulty: Hard
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/frog-jump/
// Runtime  : 103 ms (beats 48%)
// Memory   : 45672000 (beats 60%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        
        dp[0].insert(0);
        
        for (int stone : stones) {
            for (int k : dp[stone]) {
                for (int step = k - 1; step <= k + 1; ++step) {
                    if (step > 0 && dp.count(stone + step)) {
                        dp[stone + step].insert(step);
                    }
                }
            }
        }
        
        return !dp[stones.back()].empty();
    }
};