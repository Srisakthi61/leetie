// ──────────────────────────────────────────────────
// Problem  : 954. Array of Doubled Pairs
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy, Sorting
// Link     : https://leetcode.com/problems/array-of-doubled-pairs/
// Runtime  : 40 ms (beats 26%)
// Memory   : 61944000 (beats 24%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> count;
        for (int x : arr) {
            count[x]++;
        }
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for (int x : arr) {
            if (count[x] == 0) continue;
            if (count[2 * x] == 0) return false;
            count[x]--;
            count[2 * x]--;
        }
        return true;
    }
};