// ──────────────────────────────────────────────────
// Problem  : 812. Largest Triangle Area
// Difficulty: Easy
// Tags     : Array, Math, Geometry, Polygons
// Link     : https://leetcode.com/problems/largest-triangle-area/
// Runtime  : 2 ms (beats 34%)
// Memory   : 10364000 (beats 89%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double area = 0.5 * abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    );
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};