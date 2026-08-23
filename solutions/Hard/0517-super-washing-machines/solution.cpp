// ──────────────────────────────────────────────────
// Problem  : 517. Super Washing Machines
// Difficulty: Hard
// Tags     : Array, Greedy
// Link     : https://leetcode.com/problems/super-washing-machines/
// Runtime  : 0 ms (beats 100%)
// Memory   : 16748000 (beats 62%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int totalDresses = 0;
        for (int m : machines) {
            totalDresses += m;
        }
        int n = machines.size();
        if (totalDresses % n != 0) {
            return -1;
        }
        int target = totalDresses / n;
        int ans = 0;
        int balance = 0;
        for (int m : machines) {
            balance += m - target;
            ans = max({ans, abs(balance), m - target});
        }
        return ans;
    }
};