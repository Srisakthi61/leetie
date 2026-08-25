// ──────────────────────────────────────────────────
// Problem  : 592. Fraction Addition and Subtraction
// Difficulty: Medium
// Tags     : Math, String, Simulation, Euclidean Algorithm, Greatest Common Divisor
// Link     : https://leetcode.com/problems/fraction-addition-and-subtraction/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7784000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int numerator = 0, denominator = 1, num, den;
        char slash;
        while (in >> num >> slash >> den) {
            numerator = numerator * den + num * denominator;
            denominator *= den;
            int g = abs(std::gcd(numerator, denominator));
            numerator /= g;
            denominator /= g;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};