// ──────────────────────────────────────────────────
// Problem  : 792. Number of Matching Subsequences
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Binary Search, Dynamic Programming, Trie, Sorting
// Link     : https://leetcode.com/problems/number-of-matching-subsequences/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8524000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charPositions(26);
        for (int i = 0; i < s.length(); ++i) {
            charPositions[s[i] - 'a'].push_back(i);
        }

        int count = 0;
        for (const string& word : words) {
            int lastIdx = -1;
            bool found = true;
            for (char c : word) {
                const auto& positions = charPositions[c - 'a'];
                auto it = upper_bound(positions.begin(), positions.end(), lastIdx);
                if (it == positions.end()) {
                    found = false;
                    break;
                }
                lastIdx = *it;
            }
            if (found) {
                count++;
            }
        }
        return count;
    }
};