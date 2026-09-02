// ──────────────────────────────────────────────────
// Problem  : 939. Minimum Area Rectangle
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Geometry, Sorting
// Link     : https://leetcode.com/problems/minimum-area-rectangle/
// Runtime  : 101 ms (beats 92%)
// Memory   : 23292000 (beats 91%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long long> point_set;
        for (const auto& p : points) {
            point_set.insert((long long)p[0] * 40001 + p[1]);
        }
        
        int min_area = INT_MAX;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x1 != x2 && y1 != y2) {
                    if (point_set.count((long long)x1 * 40001 + y2) && 
                        point_set.count((long long)x2 * 40001 + y1)) {
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        min_area = min(min_area, area);
                    }
                }
            }
        }
        
        return min_area == INT_MAX ? 0 : min_area;
    }
};