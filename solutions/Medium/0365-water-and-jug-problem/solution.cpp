// ──────────────────────────────────────────────────
// Problem  : 365. Water and Jug Problem
// Difficulty: Medium
// Tags     : Math, Depth-First Search, Breadth-First Search, Bézout's Lemma, Euclidean Algorithm, Greatest Common Divisor, Extended Euclidean Algorithm
// Link     : https://leetcode.com/problems/water-and-jug-problem/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7656000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (x + y < target) return false;
        if (x == target || y == target || x + y == target) return true;
        return target % std::gcd(x, y) == 0;
    }
};