// ──────────────────────────────────────────────────
// Problem  : 720. Longest Word in Dictionary
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Trie, Sorting
// Link     : https://leetcode.com/problems/longest-word-in-dictionary/
// Runtime  : 20 ms (beats 67%)
// Memory   : 22368000 (beats 96%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string result = "";

        for (string& w : words) {
            if (w.length() == 1 || built.count(w.substr(0, w.length() - 1))) {
                built.insert(w);
                if (w.length() > result.length()) {
                    result = w;
                }
            }
        }

        return result;
    }
};