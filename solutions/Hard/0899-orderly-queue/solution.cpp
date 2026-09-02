// ──────────────────────────────────────────────────
// Problem  : 899. Orderly Queue
// Difficulty: Hard
// Tags     : Math, String, Sorting, Lexicographically Minimal String Rotation
// Link     : https://leetcode.com/problems/orderly-queue/
// Runtime  : 3 ms (beats 62%)
// Memory   : 13552000 (beats 35%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            for (int i = 1; i < s.length(); ++i) {
                string rotated = s.substr(i) + s.substr(0, i);
                if (rotated < ans) {
                    ans = rotated;
                }
            }
            return ans;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};