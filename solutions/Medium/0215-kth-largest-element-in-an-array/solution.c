// ──────────────────────────────────────────────────
// Problem  : 215. Kth Largest Element in an Array
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
// Link     : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Runtime  : 19 ms (beats 59%)
// Memory   : 16916000 (beats 34%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int* heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, heapSize, smallest);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }

    for (int i = (k / 2) - 1; i >= 0; i--) {
        minHeapify(heap, k, i);
    }

    for (int i = k; i < numsSize; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            minHeapify(heap, k, 0);
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}