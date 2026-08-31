// ──────────────────────────────────────────────────
// Problem  : 891. Sum of Subsequence Widths
// Difficulty: Hard
// Tags     : Array, Math, Sorting
// Link     : https://leetcode.com/problems/sum-of-subsequence-widths/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7956000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        
        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (pow2[i] - pow2[n - 1 - i]) * nums[i]) % mod;
        }
        
        return (ans + mod) % mod;
    }
};