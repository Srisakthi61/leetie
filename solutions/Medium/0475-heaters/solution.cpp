// ──────────────────────────────────────────────────
// Problem  : 475. Heaters
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Sorting
// Link     : https://leetcode.com/problems/heaters/
// Runtime  : 20 ms (beats 36%)
// Memory   : 29148000 (beats 36%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        int i = 0;
        
        for (int house : houses) {
            while (i < heaters.size() - 1 && abs(heaters[i + 1] - house) <= abs(heaters[i] - house)) {
                i++;
            }
            radius = max(radius, abs(heaters[i] - house));
        }
        
        return radius;
    }
};