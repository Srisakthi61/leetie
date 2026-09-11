// ──────────────────────────────────────────────────
// Problem  : 3483. Unique 3-Digit Even Numbers
// Difficulty: Easy
// Tags     : Array, Hash Table, Recursion, Enumeration
// Link     : https://leetcode.com/problems/unique-3-digit-even-numbers/
// Runtime  : 6 ms (beats 69%)
// Memory   : 30940000 (beats 52%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique_nums;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 != 0) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    unique_nums.insert(num);
                }
            }
        }
        return unique_nums.size();
    }
};