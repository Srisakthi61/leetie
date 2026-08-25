// ──────────────────────────────────────────────────
// Problem  : 372. Super Pow
// Difficulty: Medium
// Tags     : Math, Divide and Conquer, Euler's Totient Function, Euler's Theorem
// Link     : https://leetcode.com/problems/super-pow/
// Runtime  : 8 ms (beats 6%)
// Memory   : 15164000 (beats 86%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int power(int base, int exp) {
        int res = 1;
        base %= 1337;
        for (int i = 0; i < exp; ++i) {
            res = (res * base) % 1337;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        int p1 = power(a, last_digit);
        int p2 = power(superPow(a, b), 10);
        return (p1 * p2) % 1337;
    }
};