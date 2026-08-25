// ──────────────────────────────────────────────────
// Problem  : 398. Random Pick Index
// Difficulty: Medium
// Tags     : Hash Table, Math, Reservoir Sampling, Randomized
// Link     : https://leetcode.com/problems/random-pick-index/
// Runtime  : 1588 ms (beats 27%)
// Memory   : 50380000 (beats 91%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(nullptr));
    }
    
    int pick(int target) {
        int res = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                count++;
                if (rand() % count == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};