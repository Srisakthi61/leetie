// ──────────────────────────────────────────────────
// Problem  : 416. Partition Equal Subset Sum
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Knapsack Problem, 0-1 Knapsack
// Link     : https://leetcode.com/problems/partition-equal-subset-sum/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8064000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // If the total sum is odd, it cannot be partitioned into two equal subsets
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        // dp[i] will be true if a subset with sum i is possible
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int num : nums) {
            // Iterate backwards to ensure we use each number at most once
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }
};