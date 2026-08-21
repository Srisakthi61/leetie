// ──────────────────────────────────────────────────
// Problem  : 396. Rotate Function
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming
// Link     : https://leetcode.com/problems/rotate-function/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8224000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long f = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }
        
        long long max_f = f;
        for (int i = n - 1; i >= 1; --i) {
            f = f + sum - (long long)n * nums[i];
            max_f = max(max_f, f);
        }
        
        return max_f;
    }
};