// ──────────────────────────────────────────────────
// Problem  : 781. Rabbits in Forest
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Greedy
// Link     : https://leetcode.com/problems/rabbits-in-forest/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12032000 (beats 87%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <unordered_map>
#include <cmath>

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int ans : answers) {
            count[ans]++;
        }
        
        int res = 0;
        for (auto& pair : count) {
            int x = pair.first;
            int freq = pair.second;
            int groupSize = x + 1;
            int groups = (freq + groupSize - 1) / groupSize;
            res += groups * groupSize;
        }
        
        return res;
    }
};