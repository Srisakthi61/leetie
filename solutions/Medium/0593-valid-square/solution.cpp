// ──────────────────────────────────────────────────
// Problem  : 593. Valid Square
// Difficulty: Medium
// Tags     : Math, Geometry
// Link     : https://leetcode.com/problems/valid-square/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8760000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    long long dist(vector<int>& p1, vector<int>& p2) {
        return (long long)(p1[0] - p2[0]) * (p1[0] - p2[0]) + (long long)(p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        vector<long long> d;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                d.push_back(dist(p[i], p[j]));
            }
        }
        sort(d.begin(), d.end());
        return d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5] && d[4] == 2 * d[0];
    }
};