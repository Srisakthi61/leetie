// ──────────────────────────────────────────────────
// Problem  : 888. Fair Candy Swap
// Difficulty: Easy
// Tags     : Array, Hash Table, Binary Search, Sorting
// Link     : https://leetcode.com/problems/fair-candy-swap/
// Runtime  : 32 ms (beats 38%)
// Memory   : 52084000 (beats 16%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (sumA - sumB) / 2;
        unordered_set<int> setB(bobSizes.begin(), bobSizes.end());
        for (int x : aliceSizes) {
            if (setB.count(x - diff)) {
                return {x, x - diff};
            }
        }
        return {};
    }
};