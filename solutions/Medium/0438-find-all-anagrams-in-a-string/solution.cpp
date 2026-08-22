// ──────────────────────────────────────────────────
// Problem  : 438. Find All Anagrams in a String
// Difficulty: Medium
// Tags     : Hash Table, String, Sliding Window
// Link     : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Runtime  : 8 ms (beats 39%)
// Memory   : 11616000 (beats 37%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length()) return res;

        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int pLen = p.length();
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;
            if (i >= pLen) {
                sCount[s[i - pLen] - 'a']--;
            }
            if (sCount == pCount) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};