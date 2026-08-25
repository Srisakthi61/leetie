// ──────────────────────────────────────────────────
// Problem  : 483. Smallest Good Base
// Difficulty: Hard
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/smallest-good-base/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7972000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoull(n);
        for (int k = 60; k >= 2; --k) {
            unsigned long long l = 2, r = pow(num, 1.0 / (k - 1)) + 1;
            while (l <= r) {
                unsigned long long m = l + (r - l) / 2;
                unsigned long long sum = 0, cur = 1;
                bool overflow = false;
                for (int i = 0; i < k; ++i) {
                    sum += cur;
                    if (i < k - 1) {
                        if (__builtin_mul_overflow(cur, m, &cur)) {
                            overflow = true;
                            break;
                        }
                    }
                }
                if (!overflow && sum == num) {
                    return to_string(m);
                }
                if (overflow || sum > num) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return to_string(num - 1);
    }
};