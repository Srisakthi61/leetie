// ──────────────────────────────────────────────────
// Problem  : 532. K-diff Pairs in an Array
// Difficulty: Medium
// Tags     : Array, Hash Table, Two Pointers, Binary Search, Sorting
// Link     : https://leetcode.com/problems/k-diff-pairs-in-an-array/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8332000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        int ans = 0;
        for (auto& pair : counts) {
            int num = pair.first;
            int count = pair.second;
            
            if (k == 0) {
                if (count >= 2) {
                    ans++;
                }
            } else {
                if (counts.find(num + k) != counts.end()) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};