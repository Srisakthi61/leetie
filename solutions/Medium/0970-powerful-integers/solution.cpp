// ──────────────────────────────────────────────────
// Problem  : 970. Powerful Integers
// Difficulty: Medium
// Tags     : Hash Table, Math, Enumeration
// Link     : https://leetcode.com/problems/powerful-integers/
// Runtime  : 1 ms (beats 25%)
// Memory   : 9140000 (beats 80%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> st;
        for (long long i = 1; i <= bound; i *= x) {
            for (long long j = 1; i + j <= bound; j *= y) {
                st.insert(i + j);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(st.begin(), st.end());
    }
};