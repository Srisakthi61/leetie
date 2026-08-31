// ──────────────────────────────────────────────────
// Problem  : 805. Split Array With Same Average
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Dynamic Programming, Bit Manipulation, Meet in the Middle, Bitmask
// Link     : https://leetcode.com/problems/split-array-with-same-average/
// Runtime  : 1400 ms (beats 17%)
// Memory   : 165716000 (beats 23%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        bool possible = false;
        for (int k = 1; k <= n / 2; ++k) {
            if (sum * k % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;
        
        for (int &num : nums) {
            num = num * n - sum;
        }
        
        int n1 = n / 2;
        vector<unordered_set<int>> dp(n1 + 1);
        dp[0].insert(0);
        
        for (int num : nums) {
            for (int k = n1; k >= 1; --k) {
                for (int s : dp[k - 1]) {
                    dp[k].insert(s + num);
                }
            }
        }
        
        for (int k = 1; k <= n1; ++k) {
            if (sum * k % n == 0 && dp[k].count(0)) {
                return true;
            }
        }
        
        return false;
    }
};