// ──────────────────────────────────────────────────
// Problem  : 393. UTF-8 Validation
// Difficulty: Medium
// Tags     : Array, Bit Manipulation
// Link     : https://leetcode.com/problems/utf-8-validation/
// Runtime  : 0 ms (beats 100%)
// Memory   : 17840000 (beats 45%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (int val : data) {
            if (count == 0) {
                if ((val >> 5) == 0b110) {
                    count = 1;
                } else if ((val >> 4) == 0b1110) {
                    count = 2;
                } else if ((val >> 3) == 0b11110) {
                    count = 3;
                } else if ((val >> 7) != 0) {
                    return false;
                }
            } else {
                if ((val >> 6) != 0b10) {
                    return false;
                }
                count--;
            }
        }
        return count == 0;
    }
};