// ──────────────────────────────────────────────────
// Problem  : 645. Set Mismatch
// Difficulty: Easy
// Tags     : Array, Hash Table, Bit Manipulation, Sorting
// Link     : https://leetcode.com/problems/set-mismatch/
// Runtime  : 0 ms (beats 100%)
// Memory   : 25216000 (beats 59%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1, missing = -1;
        
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                dup = abs(nums[i]);
            } else {
                nums[idx] = -nums[idx];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        
        return {dup, missing};
    }
};