// ──────────────────────────────────────────────────
// Problem  : 1187. Make Array Strictly Increasing
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/make-array-strictly-increasing/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8280000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        
        map<int, int> dp;
        dp[-1] = 0;
        
        for (int x : arr1) {
            map<int, int> next_dp;
            for (auto& [prev, ops] : dp) {
                if (x > prev) {
                    if (next_dp.find(x) == next_dp.end() || next_dp[x] > ops) {
                        next_dp[x] = ops;
                    }
                }
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int replace_val = *it;
                    if (next_dp.find(replace_val) == next_dp.end() || next_dp[replace_val] > ops + 1) {
                        next_dp[replace_val] = ops + 1;
                    }
                }
            }
            dp = move(next_dp);
            if (dp.empty()) return -1;
        }
        
        int ans = INT_MAX;
        for (auto& [prev, ops] : dp) {
            ans = min(ans, ops);
        }
        return ans;
    }
};