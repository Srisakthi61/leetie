// ──────────────────────────────────────────────────
// Problem  : 611. Valid Triangle Number
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Greedy, Sorting
// Link     : https://leetcode.com/problems/valid-triangle-number/
// Runtime  : 31 ms (beats 67%)
// Memory   : 16528000 (beats 78%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = n - 1; i >= 2; --i) {
            int left = 0;
            int right = i - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return count;
    }
};