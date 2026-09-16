// ──────────────────────────────────────────────────
// Problem  : 1621. Number of Sets of K Non-Overlapping Line Segments
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Combinatorics, Prefix Sum
// Link     : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Runtime  : 2 ms (beats 79%)
// Memory   : 7700000 (beats 100%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numberOfSets(int n, int k) {
        long long mod = 1e9 + 7;
        long long ans = 1;
        int total = n + k - 1;
        int r = 2 * k;
        
        if (total < r) return 0;
        
        for (int i = 1; i <= r; ++i) {
            ans = ans * (total - i + 1) % mod;
            ans = ans * power(i, mod - 2) % mod;
        }
        
        return ans;
    }

private:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }
};