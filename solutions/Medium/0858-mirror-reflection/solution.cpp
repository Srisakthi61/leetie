// ──────────────────────────────────────────────────
// Problem  : 858. Mirror Reflection
// Difficulty: Medium
// Tags     : Math, Geometry, Number Theory, Least Common Multiple, Greatest Common Divisor
// Link     : https://leetcode.com/problems/mirror-reflection/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7788000 (beats 81%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2;
            q /= 2;
        }
        if (p % 2 == 0) {
            return 2;
        } else if (q % 2 == 0) {
            return 0;
        } else {
            return 1;
        }
    }
};