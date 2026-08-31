// ──────────────────────────────────────────────────
// Problem  : 837. New 21 Game
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Sliding Window, Probability and Statistics
// Link     : https://leetcode.com/problems/new-21-game/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12500000 (beats 76%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }
        
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0;
        double res = 0.0;
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = windowSum / maxPts;
            if (i < k) {
                windowSum += dp[i];
            } else {
                res += dp[i];
            }
            if (i - maxPts >= 0) {
                if (i - maxPts < k) {
                    windowSum -= dp[i - maxPts];
                }
            }
        }
        
        return res;
    }
};