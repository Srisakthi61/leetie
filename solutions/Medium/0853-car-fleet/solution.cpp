// ──────────────────────────────────────────────────
// Problem  : 853. Car Fleet
// Difficulty: Medium
// Tags     : Array, Stack, Sorting, Monotonic Stack
// Link     : https://leetcode.com/problems/car-fleet/
// Runtime  : 29 ms (beats 95%)
// Memory   : 102188000 (beats 86%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.begin(), cars.end());
        int fleets = 0;
        double maxTime = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (cars[i].second > maxTime) {
                maxTime = cars[i].second;
                fleets++;
            }
        }
        return fleets;
    }
};