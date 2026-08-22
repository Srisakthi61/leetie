// ──────────────────────────────────────────────────
// Problem  : 459. Repeated Substring Pattern
// Difficulty: Easy
// Tags     : String, String Matching, Z Algorithm, Knuth–Morris–Pratt Algorithm
// Link     : https://leetcode.com/problems/repeated-substring-pattern/
// Runtime  : 12 ms (beats 42%)
// Memory   : 15328000 (beats 57%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, t.length() - 2).find(s) != string::npos;
    }
};