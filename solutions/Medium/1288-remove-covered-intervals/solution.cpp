// ──────────────────────────────────────────────────
// Problem  : 1288. Remove Covered Intervals
// Difficulty: Medium
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/remove-covered-intervals/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8492000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = 0;
        for (const auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};