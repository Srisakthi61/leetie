// ──────────────────────────────────────────────────
// Problem  : 537. Complex Number Multiplication
// Difficulty: Medium
// Tags     : Math, String, Simulation
// Link     : https://leetcode.com/problems/complex-number-multiplication/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7652000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int real1, imag1, real2, imag2;
        char buff;
        stringstream ss1(num1), ss2(num2);
        ss1 >> real1 >> buff >> imag1 >> buff;
        ss2 >> real2 >> buff >> imag2 >> buff;
        int realResult = real1 * real2 - imag1 * imag2;
        int imagResult = real1 * imag2 + real2 * imag1;
        return to_string(realResult) + "+" + to_string(imagResult) + "i";
    }
};