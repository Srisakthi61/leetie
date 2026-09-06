// ──────────────────────────────────────────────────
// Problem  : 937. Reorder Data in Log Files
// Difficulty: Medium
// Tags     : Array, String, Sorting
// Link     : https://leetcode.com/problems/reorder-data-in-log-files/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8500000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) {
            int pos1 = log1.find(' ');
            int pos2 = log2.find(' ');
            
            bool isDigit1 = isdigit(log1[pos1 + 1]);
            bool isDigit2 = isdigit(log2[pos2 + 1]);
            
            if (!isDigit1 && !isDigit2) {
                string content1 = log1.substr(pos1 + 1);
                string content2 = log2.substr(pos2 + 1);
                if (content1 != content2) {
                    return content1 < content2;
                }
                return log1 < log2;
            }
            
            if (!isDigit1 && isDigit2) return true;
            if (isDigit1 && !isDigit2) return false;
            
            return false;
        });
        return logs;
    }
};