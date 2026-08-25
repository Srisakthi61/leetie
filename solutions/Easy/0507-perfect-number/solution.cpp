// ──────────────────────────────────────────────────
// Problem  : 507. Perfect Number
// Difficulty: Easy
// Tags     : Math
// Link     : https://leetcode.com/problems/perfect-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7784000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};