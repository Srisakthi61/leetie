// ──────────────────────────────────────────────────
// Problem  : 892. Surface Area of 3D Shapes
// Difficulty: Easy
// Tags     : Array, Math, Geometry, Matrix
// Link     : https://leetcode.com/problems/surface-area-of-3d-shapes/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8336000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    area += grid[i][j] * 4 + 2;
                }
                if (i > 0) {
                    area -= min(grid[i][j], grid[i - 1][j]) * 2;
                }
                if (j > 0) {
                    area -= min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
        
        return area;
    }
};