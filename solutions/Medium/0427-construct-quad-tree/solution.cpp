// ──────────────────────────────────────────────────
// Problem  : 427. Construct Quad Tree
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Tree, Matrix
// Link     : https://leetcode.com/problems/construct-quad-tree/
// Runtime  : 11 ms (beats 48%)
// Memory   : 19128000 (beats 42%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
    
private:
    Node* build(const vector<vector<int>>& grid, int r, int c, int len) {
        bool allSame = true;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (grid[r + i][c + j] != grid[r][c]) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) break;
        }
        
        if (allSame) {
            return new Node(grid[r][c] == 1, true);
        }
        
        int half = len / 2;
        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c + half, half);
        Node* bottomLeft = build(grid, r + half, c, half);
        Node* bottomRight = build(grid, r + half, c + half, half);
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};