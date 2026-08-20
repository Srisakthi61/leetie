// ──────────────────────────────────────────────────
// Problem  : 378. Kth Smallest Element in a Sorted Matrix
// Difficulty: Medium
// Tags     : Array, Binary Search, Sorting, Heap (Priority Queue), Matrix
// Link     : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11960000 (beats 43%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int countLessEqual(int** matrix, int n, int mid) {
    int count = 0;
    int row = n - 1;
    int col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            count += (row + 1);
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int low = matrix[0][0];
    int high = matrix[matrixSize - 1][matrixSize - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (countLessEqual(matrix, matrixSize, mid) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}