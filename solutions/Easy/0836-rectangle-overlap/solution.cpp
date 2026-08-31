// ──────────────────────────────────────────────────
// Problem  : 836. Rectangle Overlap
// Difficulty: Easy
// Tags     : Math, Geometry
// Link     : https://leetcode.com/problems/rectangle-overlap/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8272000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] || 
                 rec1[3] <= rec2[1] || 
                 rec1[0] >= rec2[2] || 
                 rec1[1] >= rec2[3]);
    }
};