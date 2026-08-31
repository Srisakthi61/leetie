// ──────────────────────────────────────────────────
// Problem  : 738. Monotone Increasing Digits
// Difficulty: Medium
// Tags     : Math, Greedy
// Link     : https://leetcode.com/problems/monotone-increasing-digits/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7896000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int m = s.length();
        int mark = m;
        for (int i = m - 1; i > 0; --i) {
            if (s[i] < s[i - 1]) {
                mark = i - 1;
                s[i - 1]--;
            }
        }
        for (int i = mark + 1; i < m; ++i) {
            s[i] = '9';
        }
        return stoi(s);
    }
};