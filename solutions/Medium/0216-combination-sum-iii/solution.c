// ──────────────────────────────────────────────────
// Problem  : 216. Combination Sum III
// Difficulty: Medium
// Tags     : Array, Backtracking
// Link     : https://leetcode.com/problems/combination-sum-iii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8796000 (beats 99%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

void backtrack(int start, int k, int target, int* current, int currentSize, int*** result, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (currentSize == k && target == 0) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        
        (*result)[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            (*result)[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    if (currentSize >= k || target < 0) {
        return;
    }

    for (int i = start; i <= 9; i++) {
        current[currentSize] = i;
        backtrack(i + 1, k, target - i, current, currentSize + 1, result, returnSize, returnColumnSizes, capacity);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int capacity = 10;
    *returnSize = 0;
    
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    
    int current[9];
    backtrack(1, k, n, current, 0, &result, returnSize, returnColumnSizes, &capacity);
    
    return result;
}