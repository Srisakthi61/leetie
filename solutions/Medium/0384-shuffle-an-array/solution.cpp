// ──────────────────────────────────────────────────
// Problem  : 384. Shuffle an Array
// Difficulty: Medium
// Tags     : Array, Math, Design, Randomized
// Link     : https://leetcode.com/problems/shuffle-an-array/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8808000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    vector<int> original;
    vector<int> current;
public:
    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }
    
    vector<int> reset() {
        current = original;
        return current;
    }
    
    vector<int> shuffle() {
        int n = current.size();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(current[i], current[j]);
        }
        return current;
    }
};