// ──────────────────────────────────────────────────
// Problem  : 963. Minimum Area Rectangle II
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Geometry
// Link     : https://leetcode.com/problems/minimum-area-rectangle-ii/
// Runtime  : 38 ms (beats 28%)
// Memory   : 12608000 (beats 85%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<long long> point_set;
        for (const auto& p : points) {
            point_set.insert((long long)p[0] * 40001 + p[1]);
        }
        
        double min_area = -1.0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
                        int x4 = x3 + x2 - x1;
                        int y4 = y3 + y2 - y1;
                        
                        if (point_set.count((long long)x4 * 40001 + y4)) {
                            double area = sqrt((long long)(x2 - x1) * (x2 - x1) + (long long)(y2 - y1) * (y2 - y1)) *
                                          sqrt((long long)(x3 - x1) * (x3 - x1) + (long long)(y3 - y1) * (y3 - y1));
                            if (min_area < 0 || area < min_area) {
                                min_area = area;
                            }
                        }
                    }
                }
            }
        }
        
        return min_area < 0 ? 0 : min_area;
    }
};