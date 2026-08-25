// ──────────────────────────────────────────────────
// Problem  : 640. Solve the Equation
// Difficulty: Medium
// Tags     : Math, String, Simulation, Linear Algebra
// Link     : https://leetcode.com/problems/solve-the-equation/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8052000 (beats 59%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string solveEquation(string equation) {
        int xCoeff = 0, constant = 0;
        int sign = 1, num = 0;
        bool hasNum = false, isX = false;
        int side = 1;

        for (int i = 0; i <= equation.length(); ++i) {
            if (i < equation.length() && equation[i] != '+' && equation[i] != '-' && equation[i] != '=') {
                if (equation[i] == 'x') {
                    isX = true;
                    if (!hasNum) num = 1;
                } else {
                    num = num * 10 + (equation[i] - '0');
                    hasNum = true;
                }
            } else {
                xCoeff += side * sign * (isX ? num : 0);
                constant += side * sign * (!isX ? num : 0);

                if (i < equation.length()) {
                    if (equation[i] == '=') {
                        side = -1;
                        sign = 1;
                    } else if (equation[i] == '-') {
                        sign = -1;
                    } else {
                        sign = 1;
                    }
                }
                num = 0;
                hasNum = false;
                isX = false;
            }
        }

        if (xCoeff == 0 && constant == 0) return "Infinite solutions";
        if (xCoeff == 0 && constant != 0) return "No solution";
        return "x=" + to_string(-constant / xCoeff);
    }
};