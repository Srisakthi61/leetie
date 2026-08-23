// ──────────────────────────────────────────────────
// Problem  : 581. Shortest Unsorted Continuous Subarray
// Difficulty: Medium
// Tags     : Array, Two Pointers, Stack, Greedy, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Runtime  : 0 ms (beats 100%)
// Memory   : 30456000 (beats 75%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = -1;
        int max_val = nums[0], min_val = nums[n - 1];
        
        for (int i = 0; i < n; i++) {
            max_val = max(max_val, nums[i]);
            if (nums[i] < max_val) {
                r = i;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            min_val = min(min_val, nums[i]);
            if (nums[i] > min_val) {
                l = i;
            }
        }
        
        return l == -1 ? 0 : r - l + 1;
    }
};