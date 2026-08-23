// ──────────────────────────────────────────────────
// Problem  : 594. Longest Harmonious Subsequence
// Difficulty: Easy
// Tags     : Array, Hash Table, Sliding Window, Sorting, Counting
// Link     : https://leetcode.com/problems/longest-harmonious-subsequence/
// Runtime  : 41 ms (beats 22%)
// Memory   : 43856000 (beats 55%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        int maxLength = 0;
        for (auto& [num, count] : countMap) {
            if (countMap.find(num + 1) != countMap.end()) {
                maxLength = max(maxLength, count + countMap[num + 1]);
            }
        }
        
        return maxLength;
    }
};