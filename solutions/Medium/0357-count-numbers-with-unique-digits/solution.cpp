// ──────────────────────────────────────────────────
// Problem  : 357. Count Numbers with Unique Digits
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Backtracking
// Link     : https://leetcode.com/problems/count-numbers-with-unique-digits/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7652000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int count = 1;
        int uniqueDigits = 9;
        int availableNumber = 9;
        for (int i = 1; i <= n && availableNumber > 0; i++) {
            if (i == 1) {
                uniqueDigits = 9;
            } else {
                uniqueDigits *= availableNumber;
                availableNumber--;
            }
            count += uniqueDigits;
        }
        return count;
    }
};