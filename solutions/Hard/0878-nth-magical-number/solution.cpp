// ──────────────────────────────────────────────────
// Problem  : 878. Nth Magical Number
// Difficulty: Hard
// Tags     : Math, Binary Search, Least Common Multiple, Inclusion-Exclusion Principle
// Link     : https://leetcode.com/problems/nth-magical-number/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7888000 (beats 44%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 1;
        long long high = (long long)n * min(a, b);
        long long lcm_val = (long long)a / std::gcd(a, b) * b;
        long long mod = 1e9 + 7;
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = mid / a + mid / b - mid / lcm_val;
            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans % mod;
    }
};