// ──────────────────────────────────────────────────
// Problem  : 1235. Maximum Profit in Job Scheduling
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8704000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        
        map<int, int> dp;
        dp[0] = 0;
        
        for (const auto& job : jobs) {
            int end = job[0], start = job[1], p = job[2];
            int prevProfit = prev(dp.upper_bound(start))->second;
            int currentProfit = prevProfit + p;
            
            if (currentProfit > dp.rbegin()->second) {
                dp[end] = currentProfit;
            }
        }
        
        return dp.rbegin()->second;
    }
};