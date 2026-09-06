// ──────────────────────────────────────────────────
// Problem  : 767. Reorganize String
// Difficulty: Medium
// Tags     : Hash Table, String, Greedy, Sorting, Heap (Priority Queue), Counting
// Link     : https://leetcode.com/problems/reorganize-string/
// Runtime  : 0 ms (beats 100%)
// Memory   : 8284000 (beats 92%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int max_freq = 0, max_char = 0;
        int n = s.length();

        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] > max_freq) {
                max_freq = count[c - 'a'];
                max_char = c - 'a';
            }
        }

        if (max_freq > (n + 1) / 2) {
            return "";
        }

        string res(n, ' ');
        int idx = 0;

        while (count[max_char] > 0) {
            res[idx] = max_char + 'a';
            idx += 2;
            count[max_char]--;
        }

        for (int i = 0; i < 26; ++i) {
            while (count[i] > 0) {
                if (idx >= n) {
                    idx = 1;
                }
                res[idx] = i + 'a';
                idx += 2;
                count[i]--;
            }
        }

        return res;
    }
};