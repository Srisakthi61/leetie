// ──────────────────────────────────────────────────
// Problem  : 833. Find And Replace in String
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Sorting
// Link     : https://leetcode.com/problems/find-and-replace-in-string/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8300000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return indices[i] > indices[j];
        });

        for (int i : p) {
            int idx = indices[i];
            string src = sources[i];
            string tgt = targets[i];
            if (s.substr(idx, src.length()) == src) {
                s.replace(idx, src.length(), tgt);
            }
        }

        return s;
    }
};