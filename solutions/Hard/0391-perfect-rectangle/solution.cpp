// ──────────────────────────────────────────────────
// Problem  : 391. Perfect Rectangle
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Geometry, Sweep Line
// Link     : https://leetcode.com/problems/perfect-rectangle/
// Runtime  : 43 ms (beats 70%)
// Memory   : 36496000 (beats 56%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        int max_a = INT_MIN;
        int max_b = INT_MIN;
        long long area = 0;
        set<pair<int, int>> corners;

        for (const auto& rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_a = max(max_a, rect[2]);
            max_b = max(max_b, rect[3]);

            area += (long long)(rect[2] - rect[0]) * (rect[3] - rect[1]);

            pair<int, int> pts[4] = {
                {rect[0], rect[1]},
                {rect[0], rect[3]},
                {rect[2], rect[1]},
                {rect[2], rect[3]}
            };

            for (int i = 0; i < 4; ++i) {
                if (corners.count(pts[i])) {
                    corners.erase(pts[i]);
                } else {
                    corners.insert(pts[i]);
                }
            }
        }

        if (corners.count({min_x, min_y}) == 0 || 
            corners.count({min_x, max_b}) == 0 || 
            corners.count({max_a, min_y}) == 0 || 
            corners.count({max_a, max_b}) == 0 || 
            corners.size() != 4) {
            return false;
        }

        long long expected_area = (long long)(max_a - min_x) * (max_b - min_y);
        
        return area == expected_area;
    }
};