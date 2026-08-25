// ──────────────────────────────────────────────────
// Problem  : 710. Random Pick with Blacklist
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Binary Search, Sorting, Randomized
// Link     : https://leetcode.com/problems/random-pick-with-blacklist/
// Runtime  : 37 ms (beats 46%)
// Memory   : 78364000 (beats 45%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    int sz;
    unordered_map<int, int> m;
public:
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        unordered_set<int> b(blacklist.begin(), blacklist.end());
        int last = n - 1;
        for (int x : blacklist) {
            if (x < sz) {
                while (b.count(last)) {
                    last--;
                }
                m[x] = last;
                last--;
            }
        }
    }
    
    int pick() {
        int r = rand() % sz;
        return m.count(r) ? m[r] : r;
    }
};