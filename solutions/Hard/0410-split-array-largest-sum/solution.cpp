// ──────────────────────────────────────────────────
// Problem  : 410. Split Array Largest Sum
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Greedy, Prefix Sum
// Link     : https://leetcode.com/problems/split-array-largest-sum/
// Runtime  : 0 ms (beats 100%)
// Memory   : 10628000 (beats 11%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            int currentSum = 0;
            int subarraysCount = 1;
            
            for (int num : nums) {
                if (currentSum + num > mid) {
                    currentSum = num;
                    subarraysCount++;
                } else {
                    currentSum += num;
                }
            }
            
            if (subarraysCount > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};