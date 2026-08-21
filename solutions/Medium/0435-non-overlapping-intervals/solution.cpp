// ──────────────────────────────────────────────────
// Problem  : 435. Non-overlapping Intervals
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy, Sorting
// Link     : https://leetcode.com/problems/non-overlapping-intervals/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8376000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int end_time = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end_time) {
                count++;
            } else {
                end_time = intervals[i][1];
            }
        }
        
        return count;
    }
};