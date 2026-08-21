// ──────────────────────────────────────────────────
// Problem  : 446. Arithmetic Slices II - Subsequence
// Difficulty: Hard
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8076000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long total_count = 0;
        vector<unordered_map<long long, int>> dp(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - (long long)nums[j];
                int count_at_j = dp[j].count(diff) ? dp[j][diff] : 0;
                
                total_count += count_at_j;
                dp[i][diff] += count_at_j + 1;
            }
        }
        
        return total_count;
    }
};