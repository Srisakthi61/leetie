// ──────────────────────────────────────────────────
// Problem  : 791. Custom Sort String
// Difficulty: Medium
// Tags     : Hash Table, String, Sorting
// Link     : https://leetcode.com/problems/custom-sort-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8152000 (beats 88%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string result = "";
        for (char c : order) {
            while (count[c - 'a'] > 0) {
                result += c;
                count[c - 'a']--;
            }
        }

        for (int i = 0; i < 26; ++i) {
            while (count[i] > 0) {
                result += (i + 'a');
                count[i]--;
            }
        }

        return result;
    }
};