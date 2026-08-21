// ──────────────────────────────────────────────────
// Problem  : 456. 132 Pattern
// Difficulty: Medium
// Tags     : Array, Binary Search, Stack, Monotonic Stack, Ordered Set
// Link     : https://leetcode.com/problems/132-pattern/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8192000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;
        int third = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) return true;

            while (!st.empty() && nums[i] > st.top()) {
                third = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};