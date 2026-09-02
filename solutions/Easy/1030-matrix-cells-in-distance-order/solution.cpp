// ──────────────────────────────────────────────────
// Problem  : 1030. Matrix Cells in Distance Order
// Difficulty: Easy
// Tags     : Array, Math, Geometry, Sorting, Matrix
// Link     : https://leetcode.com/problems/matrix-cells-in-distance-order/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8072000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                res.push_back({r, c});
            }
        }
        
        sort(res.begin(), res.end(), [rCenter, cCenter](const vector<int>& a, const vector<int>& b) {
            int distA = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int distB = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return distA < distB;
        });
        
        return res;
    }
};