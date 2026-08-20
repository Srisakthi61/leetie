// ──────────────────────────────────────────────────
// Problem  : 164. Maximum Gap
// Difficulty: Medium
// Tags     : Array, Sorting, Bucket Sort, Radix Sort, Pigeonhole Principle
// Link     : https://leetcode.com/problems/maximum-gap/
// Runtime  : 17 ms (beats 69%)
// Memory   : 24128000 (beats 56%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }

    int minVal = nums[0];
    int maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        minVal = MIN(minVal, nums[i]);
        maxVal = MAX(maxVal, nums[i]);
    }

    if (minVal == maxVal) {
        return 0;
    }

    int bucketSize = MAX(1, (maxVal - minVal) / (numsSize - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        bucketMin[idx] = MIN(bucketMin[idx], nums[i]);
        bucketMax[idx] = MAX(bucketMax[idx], nums[i]);
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) {
            continue;
        }
        maxGap = MAX(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}