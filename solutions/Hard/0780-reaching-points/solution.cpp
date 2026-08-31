// ──────────────────────────────────────────────────
// Problem  : 780. Reaching Points
// Difficulty: Hard
// Tags     : Math, Euclidean Algorithm, Greatest Common Divisor
// Link     : https://leetcode.com/problems/reaching-points/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7768000 (beats 71%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx && ty == sy) return true;
            if (tx > ty) {
                if (ty > sy) {
                    tx %= ty;
                } else {
                    return (tx - sx) % ty == 0;
                }
            } else {
                if (tx > sx) {
                    ty %= tx;
                } else {
                    return (ty - sy) % tx == 0;
                }
            }
        }
        return false;
    }
};