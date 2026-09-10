// ──────────────────────────────────────────────────
// Problem  : 1200. Minimum Absolute Difference
// Difficulty: Easy
// Tags     : Array, Sorting
// Link     : https://leetcode.com/problems/minimum-absolute-difference/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8284000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> result;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};