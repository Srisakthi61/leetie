// ──────────────────────────────────────────────────
// Problem  : 451. Sort Characters By Frequency
// Difficulty: Medium
// Tags     : Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
// Link     : https://leetcode.com/problems/sort-characters-by-frequency/
// Runtime  : 63 ms (beats 5%)
// Memory   : 10520000 (beats 93%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return a > b;
        });
        
        return s;
    }
};