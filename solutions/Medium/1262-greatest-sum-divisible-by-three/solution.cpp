// ──────────────────────────────────────────────────
// Problem  : 1262. Greatest Sum Divisible by Three
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy, Sorting
// Link     : https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8356000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};
        for (int num : nums) {
            vector<int> next_dp = dp;
            for (int i = 0; i < 3; ++i) {
                if (dp[i] != INT_MIN) {
                    int sum = dp[i] + num;
                    int rem = sum % 3;
                    next_dp[rem] = max(next_dp[rem], sum);
                }
            }
            dp = next_dp;
        }
        return dp[0];
    }
};