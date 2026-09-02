// ──────────────────────────────────────────────────
// Problem  : 973. K Closest Points to Origin
// Difficulty: Medium
// Tags     : Array, Math, Divide and Conquer, Geometry, Sorting, Heap (Priority Queue), Quickselect, K-D Tree
// Link     : https://leetcode.com/problems/k-closest-points-to-origin/
// Runtime  : 32 ms (beats 73%)
// Memory   : 66684000 (beats 89%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
    }
};