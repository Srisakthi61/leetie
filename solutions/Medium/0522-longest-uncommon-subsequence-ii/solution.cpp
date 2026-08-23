// ──────────────────────────────────────────────────
// Problem  : 522. Longest Uncommon Subsequence II
// Difficulty: Medium
// Tags     : Array, Hash Table, Two Pointers, String, Sorting
// Link     : https://leetcode.com/problems/longest-uncommon-subsequence-ii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8352000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        auto isSubsequence = [](const string& a, const string& b) {
            int i = 0, j = 0;
            while (i < a.length() && j < b.length()) {
                if (a[i] == b[j]) {
                    i++;
                }
                j++;
            }
            return i == a.length();
        };

        int maxLength = -1;
        for (int i = 0; i < n; ++i) {
            bool unique = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    unique = false;
                    break;
                }
            }
            if (unique) {
                maxLength = max(maxLength, (int)strs[i].length());
            }
        }
        return maxLength;
    }
};