// ──────────────────────────────────────────────────
// Problem  : 554. Brick Wall
// Difficulty: Medium
// Tags     : Array, Hash Table
// Link     : https://leetcode.com/problems/brick-wall/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8296000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> edge_counts;
        long long max_edges = 0;
        
        for (const auto& row : wall) {
            long long pos = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                pos += row[i];
                edge_counts[pos]++;
                max_edges = max(max_edges, (long long)edge_counts[pos]);
            }
        }
        
        return wall.size() - max_edges;
    }
};