// ──────────────────────────────────────────────────
// Problem  : 789. Escape The Ghosts
// Difficulty: Medium
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/escape-the-ghosts/
// Runtime  : 0 ms (beats 100%)
// Memory   : 13768000 (beats 99%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int myDist = abs(target[0]) + abs(target[1]);
        for (const auto& ghost : ghosts) {
            int ghostDist = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (ghostDist <= myDist) {
                return false;
            }
        }
        return true;
    }
};