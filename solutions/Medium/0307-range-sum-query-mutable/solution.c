// ──────────────────────────────────────────────────
// Problem  : 307. Range Sum Query - Mutable
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Design, Binary Indexed Tree, Segment Tree, Sqrt Decomposition
// Link     : https://leetcode.com/problems/range-sum-query-mutable/
// Runtime  : 75 ms (beats 13%)
// Memory   : 101276000 (beats 76%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int* tree;
    int* nums;
    int size;
} NumArray;

void updateBIT(NumArray* obj, int index, int val) {
    for (int i = index; i <= obj->size; i += i & (-i)) {
        obj->tree[i] += val;
    }
}

int queryBIT(NumArray* obj, int index) {
    int sum = 0;
    for (int i = index; i > 0; i -= i & (-i)) {
        sum += obj->tree[i];
    }
    return sum;
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->size = numsSize;
    obj->nums = (int*)malloc(numsSize * sizeof(int));
    obj->tree = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        obj->nums[i] = nums[i];
        updateBIT(obj, i + 1, nums[i]);
    }

    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    int diff = val - obj->nums[index];
    obj->nums[index] = val;
    updateBIT(obj, index + 1, diff);
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return queryBIT(obj, right + 1) - queryBIT(obj, left);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj->nums);
    free(obj);
}