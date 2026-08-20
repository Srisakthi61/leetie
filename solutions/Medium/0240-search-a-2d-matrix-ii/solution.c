// ──────────────────────────────────────────────────
// Problem  : 240. Search a 2D Matrix II
// Difficulty: Medium
// Tags     : Array, Binary Search, Divide and Conquer, Matrix
// Link     : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Runtime  : 3 ms (beats 0%)
// Memory   : 8388000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }

    int row = 0;
    int col = matrixColSize[0] - 1;

    while (row < matrixSize && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }

    return false;
}