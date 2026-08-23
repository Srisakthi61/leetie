// ──────────────────────────────────────────────────
// Problem  : 565. Array Nesting
// Difficulty: Medium
// Tags     : Array, Depth-First Search
// Link     : https://leetcode.com/problems/array-nesting/
// Runtime  : 6 ms (beats 55%)
// Memory   : 97048000 (beats 40%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int max_len = 0;
        vector<bool> visited(nums.size(), false);
        
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                int curr = i;
                int count = 0;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = nums[curr];
                    count++;
                }
                max_len = max(max_len, count);
            }
        }
        
        return max_len;
    }
};