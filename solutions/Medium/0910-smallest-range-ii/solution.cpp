// ──────────────────────────────────────────────────
// Problem  : 910. Smallest Range II
// Difficulty: Medium
// Tags     : Array, Math, Greedy, Sorting
// Link     : https://leetcode.com/problems/smallest-range-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 19284000 (beats 76%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        
        for (int i = 0; i < n - 1; ++i) {
            int high = max(nums[n - 1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, high - low);
        }
        
        return ans;
    }
};