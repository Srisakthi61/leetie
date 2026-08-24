// ──────────────────────────────────────────────────
// Problem  : 630. Course Schedule III
// Difficulty: Hard
// Tags     : Array, Greedy, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/course-schedule-iii/
// Runtime  : 27 ms (beats 69%)
// Memory   : 60532000 (beats 39%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        int total_time = 0;
        
        for (const auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            
            total_time += duration;
            pq.push(duration);
            
            if (total_time > lastDay) {
                total_time -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};