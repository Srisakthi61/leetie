// ──────────────────────────────────────────────────
// Problem  : 575. Distribute Candies
// Difficulty: Easy
// Tags     : Array, Hash Table
// Link     : https://leetcode.com/problems/distribute-candies/
// Runtime  : 101 ms (beats 64%)
// Memory   : 120060000 (beats 60%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> unique_candies(candyType.begin(), candyType.end());
        return min(unique_candies.size(), candyType.size() / 2);
    }
};