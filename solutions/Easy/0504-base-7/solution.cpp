// ──────────────────────────────────────────────────
// Problem  : 504. Base 7
// Difficulty: Easy
// Tags     : Math, String
// Link     : https://leetcode.com/problems/base-7/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8328000 (beats 13%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "";
        bool negative = num < 0;
        long long n = abs((long long)num);
        while (n > 0) {
            res += to_string(n % 7);
            n /= 7;
        }
        if (negative) res += "-";
        reverse(res.begin(), res.end());
        return res;
    }
};