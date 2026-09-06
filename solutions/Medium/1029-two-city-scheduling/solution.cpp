// ──────────────────────────────────────────────────
// Problem  : 1029. Two City Scheduling
// Difficulty: Medium
// Tags     : Array, Greedy, Sorting, Hungarian Algorithm, Successive Shortest Path Algorithm
// Link     : https://leetcode.com/problems/two-city-scheduling/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10924000 (beats 82%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        int totalCost = 0;
        int n = costs.size() / 2;
        
        for (int i = 0; i < n; ++i) {
            totalCost += costs[i][0];
        }
        for (int i = n; i < costs.size(); ++i) {
            totalCost += costs[i][1];
        }
        
        return totalCost;
    }
};