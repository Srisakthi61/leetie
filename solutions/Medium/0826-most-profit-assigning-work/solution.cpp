// ──────────────────────────────────────────────────
// Problem  : 826. Most Profit Assigning Work
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Greedy, Sorting
// Link     : https://leetcode.com/problems/most-profit-assigning-work/
// Runtime  : 7 ms (beats 85%)
// Memory   : 40444000 (beats 86%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int best = 0;
        int i = 0;
        
        for (int ability : worker) {
            while (i < n && jobs[i].first <= ability) {
                best = max(best, jobs[i].second);
                i++;
            }
            maxProfit += best;
        }

        return maxProfit;
    }
};