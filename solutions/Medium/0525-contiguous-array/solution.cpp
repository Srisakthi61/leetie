// ──────────────────────────────────────────────────
// Problem  : 525. Contiguous Array
// Difficulty: Medium
// Tags     : Array, Hash Table, Prefix Sum
// Link     : https://leetcode.com/problems/contiguous-array/
// Runtime  : 31 ms (beats 20%)
// Memory   : 88284000 (beats 73%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int max_len = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += (nums[i] == 1 ? 1 : -1);
            if (mp.find(count) != mp.end()) {
                max_len = max(max_len, i - mp[count]);
            } else {
                mp[count] = i;
            }
        }
        return max_len;
    }
};