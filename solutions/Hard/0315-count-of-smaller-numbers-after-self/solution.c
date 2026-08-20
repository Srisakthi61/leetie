// ──────────────────────────────────────────────────
// Problem  : 315. Count of Smaller Numbers After Self
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Segment Tree, Merge Sort, Ordered Set, Treap
// Link     : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Runtime  : 111 ms (beats 55%)
// Memory   : 75896000 (beats 39%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, Element* temp, int* counts) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            rightCount++;
            temp[k++] = arr[j++];
        } else {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Element* arr, int left, int right, Element* temp, int* counts) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, temp, counts);
    mergeSort(arr, mid + 1, right, temp, counts);
    merge(arr, left, mid, right, temp, counts);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    if (numsSize == 0) return counts;

    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    Element* temp = (Element*)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, temp, counts);

    free(arr);
    free(temp);

    return counts;
}