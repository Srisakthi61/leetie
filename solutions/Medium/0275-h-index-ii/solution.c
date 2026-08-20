// ──────────────────────────────────────────────────
// Problem  : 275. H-Index II
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/h-index-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12376000 (beats 47%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int hIndex(int* citations, int citationsSize) {
    int left = 0;
    int right = citationsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] >= citationsSize - mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return citationsSize - left;
}