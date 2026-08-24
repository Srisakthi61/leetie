// ──────────────────────────────────────────────────
// Problem  : 646. Maximum Length of Pair Chain
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Greedy, Sorting, Longest Increasing Subsequence
// Link     : https://leetcode.com/problems/maximum-length-of-pair-chain/
// Runtime  : 3 ms (beats 85%)
// Memory   : 26456000 (beats 82%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int current_end = INT_MIN;
        int chain_length = 0;
        
        for (const auto& p : pairs) {
            if (p[0] > current_end) {
                current_end = p[1];
                chain_length++;
            }
        }
        
        return chain_length;
    }
};