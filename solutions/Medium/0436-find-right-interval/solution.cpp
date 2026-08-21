// ──────────────────────────────────────────────────
// Problem  : 436. Find Right Interval
// Difficulty: Medium
// Tags     : Array, Binary Search, Sorting
// Link     : https://leetcode.com/problems/find-right-interval/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8428000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> starts;
        int n = intervals.size();
        
        // Store the start time and its original index in the map.
        // std::map automatically sorts elements by their keys (start times).
        for (int i = 0; i < n; ++i) {
            starts[intervals[i][0]] = i;
        }
        
        vector<int> res(n, -1);
        
        // For each interval, find the right interval using binary search (lower_bound)
        for (int i = 0; i < n; ++i) {
            auto it = starts.lower_bound(intervals[i][1]);
            
            // If an interval is found that starts after or at the same time the current one ends
            if (it != starts.end()) {
                res[i] = it->second;
            }
        }
        
        return res;
    }
};