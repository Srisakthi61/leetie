// ──────────────────────────────────────────────────
// Problem  : 754. Reach a Number
// Difficulty: Medium
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/reach-a-number/
// Runtime  : 0 ms (beats 100%)
// Memory   : 7724000 (beats 82%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long k = 0;
        long long sum = 0;
        
        while (sum < target) {
            k++;
            sum += k;
        }
        
        long long diff = sum - target;
        if (diff % 2 == 0) {
            return k;
        } else if ((k + 1) % 2 != 0) {
            return k + 1;
        } else {
            return k + 2;
        }
    }
};