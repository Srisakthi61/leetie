// ──────────────────────────────────────────────────
// Problem  : 494. Target Sum
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Backtracking, Knapsack Problem, 0-1 Knapsack
// Link     : https://leetcode.com/problems/target-sum/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12284000 (beats 73%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        if (abs(target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }
        
        int s1 = (sum + target) / 2;
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1;
        
        for (int num : nums) {
            for (int j = s1; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[s1];
    }
};