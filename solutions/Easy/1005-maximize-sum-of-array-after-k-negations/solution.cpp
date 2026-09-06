// ──────────────────────────────────────────────────
// Problem  : 1005. Maximize Sum Of Array After K Negations
// Difficulty: Easy
// Tags     : Array, Greedy, Sorting
// Link     : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12716000 (beats 58%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && k > 0; ++i) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        
        sort(nums.begin(), nums.end());
        if (k % 2 != 0) {
            nums[0] = -nums[0];
        }
        
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        return sum;
    }
};