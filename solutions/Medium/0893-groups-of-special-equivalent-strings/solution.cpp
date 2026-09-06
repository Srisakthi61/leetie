// ──────────────────────────────────────────────────
// Problem  : 893. Groups of Special-Equivalent Strings
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Sorting
// Link     : https://leetcode.com/problems/groups-of-special-equivalent-strings/
// Runtime  : 3 ms (beats 58%)
// Memory   : 11816000 (beats 99%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> seen;
        for (string& word : words) {
            string odd = "", even = "";
            for (int i = 0; i < word.length(); ++i) {
                if (i % 2 == 0) {
                    even += word[i];
                } else {
                    odd += word[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            seen.insert(even + odd);
        }
        return seen.size();
    }
};