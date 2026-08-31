// ──────────────────────────────────────────────────
// Problem  : 808. Soup Servings
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Probability and Statistics
// Link     : https://leetcode.com/problems/soup-servings/
// Runtime  : 2 ms (beats 67%)
// Memory   : 9756000 (beats 84%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) {
            return 1.0;
        }
        
        int m = (n + 24) / 25;
        vector<vector<double>> memo(m + 1, vector<double>(m + 1, -1.0));
        
        return dp(m, m, memo);
    }

private:
    double dp(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        
        if (memo[a][b] != -1.0) {
            return memo[a][b];
        }
        
        memo[a][b] = 0.25 * (
            dp(a - 4, b, memo) +
            dp(a - 3, b - 1, memo) +
            dp(a - 2, b - 2, memo) +
            dp(a - 1, b - 3, memo)
        );
        
        return memo[a][b];
    }
};