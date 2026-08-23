// ──────────────────────────────────────────────────
// Problem  : 566. Reshape the Matrix
// Difficulty: Easy
// Tags     : Array, Matrix, Simulation
// Link     : https://leetcode.com/problems/reshape-the-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 15104000 (beats 55%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if (m * n != r * c) {
            return mat;
        }
        
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        
        return res;
    }
};