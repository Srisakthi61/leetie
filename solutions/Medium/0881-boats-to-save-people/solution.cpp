// ──────────────────────────────────────────────────
// Problem  : 881. Boats to Save People
// Difficulty: Medium
// Tags     : Array, Two Pointers, Greedy, Sorting, Timsort
// Link     : https://leetcode.com/problems/boats-to-save-people/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8264000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        
        return boats;
    }
};