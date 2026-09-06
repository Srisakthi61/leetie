// ──────────────────────────────────────────────────
// Problem  : 1054. Distant Barcodes
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
// Link     : https://leetcode.com/problems/distant-barcodes/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8416000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        int maxCount = 0, mostFrequent = 0;
        for (int b : barcodes) {
            count[b]++;
            if (count[b] > maxCount) {
                maxCount = count[b];
                mostFrequent = b;
            }
        }
        
        int n = barcodes.size();
        vector<int> res(n);
        int idx = 0;
        
        for (int i = 0; i < maxCount; ++i) {
            res[idx] = mostFrequent;
            idx += 2;
        }
        count.erase(mostFrequent);
        
        for (auto& [b, freq] : count) {
            for (int i = 0; i < freq; ++i) {
                if (idx >= n) idx = 1;
                res[idx] = b;
                idx += 2;
            }
        }
        
        return res;
    }
};