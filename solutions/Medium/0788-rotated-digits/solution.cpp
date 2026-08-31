// ──────────────────────────────────────────────────
// Problem  : 788. Rotated Digits
// Difficulty: Medium
// Tags     : Math, Dynamic Programming
// Link     : https://leetcode.com/problems/rotated-digits/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7748000 (beats 84%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }

private:
    bool isGood(int x) {
        bool isValidRotated = false;
        while (x > 0) {
            int d = x % 10;
            if (d == 3 || d == 4 || d == 7) {
                return false;
            }
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                isValidRotated = true;
            }
            x /= 10;
        }
        return isValidRotated;
    }
};