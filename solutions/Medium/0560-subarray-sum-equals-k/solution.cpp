// ──────────────────────────────────────────────────
// Problem  : 560. Subarray Sum Equals K
// Difficulty: Medium
// Tags     : Array, Hash Table, Prefix Sum
// Link     : https://leetcode.com/problems/subarray-sum-equals-k/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8292000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        int current_sum = 0;
        int ans = 0;
        
        for (int num : nums) {
            current_sum += num;
            if (prefix_counts.find(current_sum - k) != prefix_counts.end()) {
                ans += prefix_counts[current_sum - k];
            }
            prefix_counts[current_sum]++;
        }
        
        return ans;
    }
};