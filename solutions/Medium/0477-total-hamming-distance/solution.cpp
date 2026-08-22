// ──────────────────────────────────────────────────
// Problem  : 477. Total Hamming Distance
// Difficulty: Medium
// Tags     : Array, Math, Bit Manipulation
// Link     : https://leetcode.com/problems/total-hamming-distance/
// Runtime  : 4 ms (beats 91%)
// Memory   : 22904000 (beats 14%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (int num : nums) {
                ones += (num >> i) & 1;
            }
            int zeros = n - ones;
            total += ones * zeros;
        }
        return total;
    }
};