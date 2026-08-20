// ──────────────────────────────────────────────────
// Problem  : 274. H-Index
// Difficulty: Medium
// Tags     : Array, Sorting, Counting Sort
// Link     : https://leetcode.com/problems/h-index/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8516000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int hIndex(int* citations, int citationsSize) {
    int count[citationsSize + 1];
    for (int i = 0; i <= citationsSize; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= citationsSize) {
            count[citationsSize]++;
        } else {
            count[citations[i]]++;
        }
    }

    int total = 0;
    for (int i = citationsSize; i >= 0; i--) {
        total += count[i];
        if (total >= i) {
            return i;
        }
    }

    return 0;
}