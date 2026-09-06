// ──────────────────────────────────────────────────
// Problem  : 768. Max Chunks To Make Sorted II
// Difficulty: Hard
// Tags     : Array, Stack, Greedy, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 16616000 (beats 32%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxOfLeft(n);
        vector<int> minOfRight(n + 1, INT_MAX);

        maxOfLeft[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            maxOfLeft[i] = max(maxOfLeft[i - 1], arr[i]);
        }

        for (int i = n - 1; i >= 0; --i) {
            minOfRight[i] = min(minOfRight[i + 1], arr[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n; ++i) {
            if (maxOfLeft[i] <= minOfRight[i + 1]) {
                chunks++;
            }
        }

        return chunks;
    }
};