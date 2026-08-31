// ──────────────────────────────────────────────────
// Problem  : 762. Prime Number of Set Bits in Binary Representation
// Difficulty: Easy
// Tags     : Math, Bit Manipulation, Primality Test
// Link     : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7832000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            int setBits = __builtin_popcount(i);
            if (setBits == 2 || setBits == 3 || setBits == 5 || setBits == 7 || 
                setBits == 11 || setBits == 13 || setBits == 17 || setBits == 19) {
                count++;
            }
        }
        return count;
    }
};