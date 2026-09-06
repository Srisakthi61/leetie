// ──────────────────────────────────────────────────
// Problem  : 857. Minimum Cost to Hire K Workers
// Difficulty: Hard
// Tags     : Array, Greedy, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// Runtime  : 5 ms (beats 94%)
// Memory   : 29592000 (beats 92%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for (int i = 0; i < n; ++i) {
            workers[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        sort(workers.begin(), workers.end());
        
        double minCost = DBL_MAX;
        int qualitySum = 0;
        priority_queue<int> pq;
        
        for (int i = 0; i < n; ++i) {
            double ratio = workers[i].first;
            int q = workers[i].second;
            
            qualitySum += q;
            pq.push(q);
            
            if (pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                minCost = min(minCost, qualitySum * ratio);
            }
        }
        
        return minCost;
    }
};