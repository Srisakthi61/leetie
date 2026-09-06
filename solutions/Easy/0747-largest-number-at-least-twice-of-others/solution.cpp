// ──────────────────────────────────────────────────
// Problem  : 747. Largest Number At Least Twice of Others
// Difficulty: Easy
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8028000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != maxIndex && nums[maxIndex] < 2 * nums[i]) {
                return -1;
            }
        }
        
        return maxIndex;
    }
};