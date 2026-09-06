// ──────────────────────────────────────────────────
// Problem  : 825. Friends Of Appropriate Ages
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Sorting
// Link     : https://leetcode.com/problems/friends-of-appropriate-ages/
// Runtime  : 0 ms (beats 100%)
// Memory   : 41380000 (beats 18%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) {
            count[age]++;
        }

        vector<int> cumulative(121, 0);
        for (int i = 1; i <= 120; ++i) {
            cumulative[i] = cumulative[i - 1] + count[i];
        }

        int ans = 0;
        for (int age = 15; age <= 120; ++age) {
            if (count[age] == 0) continue;
            int lowerBound = 0.5 * age + 7;
            if (lowerBound >= age) continue;
            
            int requests = cumulative[age] - cumulative[lowerBound];
            ans += count[age] * (requests - 1);
        }

        return ans;
    }
};