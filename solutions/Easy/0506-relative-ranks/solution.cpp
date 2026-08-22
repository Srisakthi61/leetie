// ──────────────────────────────────────────────────
// Problem  : 506. Relative Ranks
// Difficulty: Easy
// Tags     : Array, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/relative-ranks/
// Runtime  : 2 ms (beats 0%)
// Memory   : 8324000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> athletes(n);
        for (int i = 0; i < n; ++i) {
            athletes[i] = {score[i], i};
        }
        
        sort(athletes.rbegin(), athletes.rend());
        
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result[athletes[i].second] = "Gold Medal";
            } else if (i == 1) {
                result[athletes[i].second] = "Silver Medal";
            } else if (i == 2) {
                result[athletes[i].second] = "Bronze Medal";
            } else {
                result[athletes[i].second] = to_string(i + 1);
            }
        }
        
        return result;
    }
};