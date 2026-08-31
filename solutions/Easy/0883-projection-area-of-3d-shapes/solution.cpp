// ──────────────────────────────────────────────────
// Problem  : 883. Projection Area of 3D Shapes
// Difficulty: Easy
// Tags     : Array, Math, Geometry, Matrix
// Link     : https://leetcode.com/problems/projection-area-of-3d-shapes/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8340000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int maxRow = 0, maxCol = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ans++;
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            ans += maxRow + maxCol;
        }
        return ans;
    }
};