// ──────────────────────────────────────────────────
// Problem  : 454. 4Sum II
// Difficulty: Medium
// Tags     : Array, Hash Table
// Link     : https://leetcode.com/problems/4sum-ii/
// Runtime  : 109 ms (beats 35%)
// Memory   : 28112000 (beats 60%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumCount;
        
        // Store all possible sums of pairs from nums1 and nums2 in a hash map
        for (int a : nums1) {
            for (int b : nums2) {
                sumCount[a + b]++;
            }
        }
        
        int count = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                if (sumCount.count(target)) {
                    count += sumCount[target];
                }
            }
        }
        
        return count;
    }
};