// ──────────────────────────────────────────────────
// Problem  : 447. Number of Boomerangs
// Difficulty: Medium
// Tags     : Array, Hash Table, Math
// Link     : https://leetcode.com/problems/number-of-boomerangs/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8396000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> distCount;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dist = dx * dx + dy * dy;
                
                distCount[dist]++;
            }
            
            for (auto& pair : distCount) {
                result += pair.second * (pair.second - 1);
            }
        }
        
        return result;
    }
};