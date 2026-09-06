// ──────────────────────────────────────────────────
// Problem  : 1048. Longest String Chain
// Difficulty: Medium
// Tags     : Array, Hash Table, Two Pointers, String, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/longest-string-chain/
// Runtime  : 38 ms (beats 79%)
// Memory   : 21552000 (beats 53%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_map<string, int> dp;
        int maxChain = 1;
        
        for (const string& word : words) {
            int currentLength = 1;
            for (int i = 0; i < word.length(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(predecessor)) {
                    currentLength = max(currentLength, dp[predecessor] + 1);
                }
            }
            dp[word] = currentLength;
            maxChain = max(maxChain, currentLength);
        }
        
        return maxChain;
    }
};