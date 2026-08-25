// ──────────────────────────────────────────────────
// Problem  : 519. Random Flip Matrix
// Difficulty: Medium
// Tags     : Hash Table, Math, Reservoir Sampling, Randomized
// Link     : https://leetcode.com/problems/random-flip-matrix/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8960000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    int rows, cols, total;
    unordered_map<int, int> mapped;
public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        total = m * n;
        reset();
    }
    
    vector<int> flip() {
        int r = rand() % total;
        total--;
        int idx = mapped.count(r) ? mapped[r] : r;
        mapped[r] = mapped.count(total) ? mapped[total] : total;
        return {idx / cols, idx % cols};
    }
    
    void reset() {
        total = rows * cols;
        mapped.clear();
    }
};