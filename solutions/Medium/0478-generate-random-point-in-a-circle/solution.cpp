// ──────────────────────────────────────────────────
// Problem  : 478. Generate Random Point in a Circle
// Difficulty: Medium
// Tags     : Math, Geometry, Rejection Sampling, Randomized
// Link     : https://leetcode.com/problems/generate-random-point-in-a-circle/
// Runtime  : 15 ms (beats 49%)
// Memory   : 35124000 (beats 19%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    double rad, xc, yc;
public:
    Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        double len = sqrt((double)rand() / RAND_MAX) * rad;
        double deg = ((double)rand() / RAND_MAX) * 2 * M_PI;
        return {xc + len * cos(deg), yc + len * sin(deg)};
    }
};