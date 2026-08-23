// ──────────────────────────────────────────────────
// Problem  : 539. Minimum Time Difference
// Difficulty: Medium
// Tags     : Array, Math, String, Sorting
// Link     : https://leetcode.com/problems/minimum-time-difference/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8304000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        
        sort(minutes.begin(), minutes.end());
        
        int min_diff = 24 * 60 - minutes.back() + minutes.front();
        for (int i = 1; i < minutes.size(); i++) {
            min_diff = min(min_diff, minutes[i] - minutes[i - 1]);
        }
        
        return min_diff;
    }
};