// ──────────────────────────────────────────────────
// Problem  : 492. Construct the Rectangle
// Difficulty: Easy
// Tags     : Math
// Link     : https://leetcode.com/problems/construct-the-rectangle/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7932000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w != 0) {
            w--;
        }
        return {area / w, w};
    }
};