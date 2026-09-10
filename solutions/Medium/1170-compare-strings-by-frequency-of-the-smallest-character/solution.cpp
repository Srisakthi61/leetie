// ──────────────────────────────────────────────────
// Problem  : 1170. Compare Strings by Frequency of the Smallest Character
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Binary Search, Sorting
// Link     : https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8592000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int f(string s) {
        char smallest = s[0];
        int count = 0;
        for (char c : s) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                count++;
            }
        }
        return count;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordFreqs;
        for (const string& w : words) {
            wordFreqs.push_back(f(w));
        }
        sort(wordFreqs.begin(), wordFreqs.end());

        vector<int> result;
        for (const string& q : queries) {
            int qFreq = f(q);
            auto it = upper_bound(wordFreqs.begin(), wordFreqs.end(), qFreq);
            result.push_back(wordFreqs.end() - it);
        }

        return result;
    }
};