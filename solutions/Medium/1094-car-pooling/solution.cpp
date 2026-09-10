// ──────────────────────────────────────────────────
// Problem  : 1094. Car Pooling
// Difficulty: Medium
// Tags     : Array, Sorting, Heap (Priority Queue), Simulation, Prefix Sum
// Link     : https://leetcode.com/problems/car-pooling/
// Runtime  : 0 ms (beats 100%)
// Memory   : 14272000 (beats 81%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timestamp(1001, 0);
        for (const auto& trip : trips) {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }
        int currentPassengers = 0;
        for (int passengers : timestamp) {
            currentPassengers += passengers;
            if (currentPassengers > capacity) {
                return false;
            }
        }
        return true;
    }
};