// ──────────────────────────────────────────────────
// Problem  : 1012. Numbers With Repeated Digits
// Difficulty: Hard
// Tags     : Math, Dynamic Programming
// Link     : https://leetcode.com/problems/numbers-with-repeated-digits/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8076000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int len = s.length();
        int uniqueCount = 0;

        for (int i = 1; i < len; ++i) {
            uniqueCount += 9 * perm(9, i - 1);
        }

        unordered_set<int> seen;
        for (int i = 0; i < len; ++i) {
            int start = (i == 0) ? 1 : 0;
            for (int d = start; d < s[i] - '0'; ++d) {
                if (!seen.count(d)) {
                    uniqueCount += perm(10 - i - 1, len - i - 1);
                }
            }
            if (seen.count(s[i] - '0')) {
                break;
            }
            seen.insert(s[i] - '0');
            if (i == len - 1) {
                uniqueCount++;
            }
        }

        return n - uniqueCount;
    }

private:
    int perm(int m, int k) {
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= (m - i);
        }
        return res;
    }
};
