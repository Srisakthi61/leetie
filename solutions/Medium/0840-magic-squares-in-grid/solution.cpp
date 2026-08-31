// ──────────────────────────────────────────────────
// Problem  : 840. Magic Squares In Grid
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Matrix
// Link     : https://leetcode.com/problems/magic-squares-in-grid/
// Runtime  : 3 ms (beats 23%)
// Memory   : 11472000 (beats 78%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        auto isMagic = [&](int r, int c) {
            vector<bool> seen(10, false);
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int val = grid[r + i][c + j];
                    if (val < 1 || val > 9 || seen[val]) return false;
                    seen[val] = true;
                }
            }

            int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
            for (int i = 0; i < 3; ++i) {
                if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
                if (grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
            }

            if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
            if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;

            return true;
        };

        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (grid[i+1][j+1] == 5 && isMagic(i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};