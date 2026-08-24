// ──────────────────────────────────────────────────
// Problem  : 643. Maximum Average Subarray I
// Difficulty: Easy
// Tags     : Array, Sliding Window
// Link     : https://leetcode.com/problems/maximum-average-subarray-i/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8276000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        double max_sum = current_sum;
        
        for (int i = k; i < nums.size(); ++i) {
            current_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum / k;
    }
};