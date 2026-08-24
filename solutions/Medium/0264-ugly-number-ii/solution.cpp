// ──────────────────────────────────────────────────
// Problem  : 264. Ugly Number II
// Difficulty: Medium
// Tags     : Hash Table, Math, Dynamic Programming, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/ugly-number-ii/
// Runtime  : 3 ms (beats 78%)
// Memory   : 11292000 (beats 83%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < n; i++) {
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;
            
            int nextUgly = min({next2, next3, next5});
            dp[i] = nextUgly;
            
            if (nextUgly == next2) p2++;
            if (nextUgly == next3) p3++;
            if (nextUgly == next5) p5++;
        }
        
        return dp[n - 1];
    }
};
