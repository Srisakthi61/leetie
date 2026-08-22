// ──────────────────────────────────────────────────
// Problem  : 491. Non-decreasing Subsequences
// Difficulty: Medium
// Tags     : Array, Hash Table, Backtracking, Bit Manipulation
// Link     : https://leetcode.com/problems/non-decreasing-subsequences/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8720000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() >= 2) {
            result.push_back(current);
        }
        
        unordered_set<int> used;
        for (int i = start; i < nums.size(); ++i) {
            if (!current.empty() && nums[i] < current.back()) {
                continue;
            }
            if (used.count(nums[i])) {
                continue;
            }
            
            used.insert(nums[i]);
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};