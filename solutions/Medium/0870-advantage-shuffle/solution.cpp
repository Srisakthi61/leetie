// ──────────────────────────────────────────────────
// Problem  : 870. Advantage Shuffle
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy, Sorting
// Link     : https://leetcode.com/problems/advantage-shuffle/
// Runtime  : 103 ms (beats 24%)
// Memory   : 78072000 (beats 30%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> res(n);
        multiset<int> s(nums1.begin(), nums1.end());
        for (int i = 0; i < n; ++i) {
            auto it = s.upper_bound(nums2[i]);
            if (it == s.end()) {
                it = s.begin();
            }
            res[i] = *it;
            s.erase(it);
        }
        return res;
    }
};