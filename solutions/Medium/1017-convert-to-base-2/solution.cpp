// ──────────────────────────────────────────────────
// Problem  : 1017. Convert to Base -2
// Difficulty: Medium
// Tags     : Math
// Link     : https://leetcode.com/problems/convert-to-base-2/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7752000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string res = "";
        while (n != 0) {
            int rem = n % -2;
            n /= -2;
            if (rem < 0) {
                rem += 2;
                n += 1;
            }
            res += to_string(rem);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};