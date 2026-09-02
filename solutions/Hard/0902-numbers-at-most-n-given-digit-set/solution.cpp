// ──────────────────────────────────────────────────
// Problem  : 902. Numbers At Most N Given Digit Set
// Difficulty: Hard
// Tags     : Array, Math, String, Binary Search, Dynamic Programming
// Link     : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8720000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int k = s.length();
        int m = digits.size();
        int total = 0;
        
        for (int i = 1; i < k; ++i) {
            total += pow(m, i);
        }
        
        for (int i = 0; i < k; ++i) {
            bool prefixMatch = false;
            for (const string& d : digits) {
                if (d[0] < s[i]) {
                    total += pow(m, k - 1 - i);
                } else if (d[0] == s[i]) {
                    prefixMatch = true;
                    break;
                } else {
                    break;
                }
            }
            if (!prefixMatch) {
                return total;
            }
        }
        
        return total + 1;
    }
};