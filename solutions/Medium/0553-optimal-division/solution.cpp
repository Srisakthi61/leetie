// ──────────────────────────────────────────────────
// Problem  : 553. Optimal Division
// Difficulty: Medium
// Tags     : Array, Math, Dynamic Programming
// Link     : https://leetcode.com/problems/optimal-division/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10400000 (beats 97%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return to_string(nums[0]);
        }
        if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < n; i++) {
            res += "/" + to_string(nums[i]);
        }
        res += ")";
        return res;
    }
};