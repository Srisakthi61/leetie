// ──────────────────────────────────────────────────
// Problem  : 976. Largest Perimeter Triangle
// Difficulty: Easy
// Tags     : Array, Math, Greedy, Sorting, Quicksort, Polygons
// Link     : https://leetcode.com/problems/largest-perimeter-triangle/
// Runtime  : 3 ms (beats 80%)
// Memory   : 25548000 (beats 79%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};