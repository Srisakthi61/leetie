// ──────────────────────────────────────────────────
// Problem  : 523. Continuous Subarray Sum
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Prefix Sum, Pigeonhole Principle
// Link     : https://leetcode.com/problems/continuous-subarray-sum/
// Runtime  : 75 ms (beats 79%)
// Memory   : 146352000 (beats 57%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int remainder = currentSum % k;
            
            if (remainderMap.find(remainder) != remainderMap.end()) {
                if (i - remainderMap[remainder] >= 2) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};