// ──────────────────────────────────────────────────
// Problem  : 479. Largest Palindrome Product
// Difficulty: Hard
// Tags     : Math, Enumeration
// Link     : https://leetcode.com/problems/largest-palindrome-product/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7972000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        long max_num = pow(10, n) - 1;
        long min_num = pow(10, n - 1);
        for (long i = max_num; i >= min_num; --i) {
            string s = to_string(i);
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            long palindrome = stol(s + rev_s);
            for (long j = max_num; j * j >= palindrome; --j) {
                if (palindrome % j == 0) {
                    return palindrome % 1337;
                }
            }
        }
        return 0;
    }
};