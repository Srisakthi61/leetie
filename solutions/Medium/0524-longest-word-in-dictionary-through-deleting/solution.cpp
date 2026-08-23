// ──────────────────────────────────────────────────
// Problem  : 524. Longest Word in Dictionary through Deleting
// Difficulty: Medium
// Tags     : Array, Two Pointers, String, Sorting
// Link     : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Runtime  : 10 ms (beats 63%)
// Memory   : 18992000 (beats 92%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string longestWord = "";
        for (const string& word : dictionary) {
            int i = 0, j = 0;
            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    j++;
                }
                i++;
            }
            if (j == word.length()) {
                if (word.length() > longestWord.length() || 
                    (word.length() == longestWord.length() && word < longestWord)) {
                    longestWord = word;
                }
            }
        }
        return longestWord;
    }
};