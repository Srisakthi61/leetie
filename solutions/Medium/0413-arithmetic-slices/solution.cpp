// ──────────────────────────────────────────────────
// Problem  : 413. Arithmetic Slices
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Sliding Window
// Link     : https://leetcode.com/problems/arithmetic-slices/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10624000 (beats 99%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        
        int total = 0;
        int currentSlices = 0;
        
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                currentSlices += 1;
                total += currentSlices;
            } else {
                currentSlices = 0;
            }
        }
        
        return total;
    }
};