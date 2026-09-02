// ──────────────────────────────────────────────────
// Problem  : 932. Beautiful Array
// Difficulty: Medium
// Tags     : Array, Math, Divide and Conquer
// Link     : https://leetcode.com/problems/beautiful-array/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10068000 (beats 62%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};
        while (res.size() < n) {
            vector<int> temp;
            for (int x : res) {
                if (2 * x - 1 <= n) temp.push_back(2 * x - 1);
            }
            for (int x : res) {
                if (2 * x <= n) temp.push_back(2 * x);
            }
            res = temp;
        }
        return res;
    }
};