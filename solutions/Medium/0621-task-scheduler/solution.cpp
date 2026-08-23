// ──────────────────────────────────────────────────
// Problem  : 621. Task Scheduler
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
// Link     : https://leetcode.com/problems/task-scheduler/
// Runtime  : 0 ms (beats 100%)
// Memory   : 38152000 (beats 96%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int max_freq = 0;
        int max_count = 0;

        for (char task : tasks) {
            count[task - 'A']++;
            if (count[task - 'A'] > max_freq) {
                max_freq = count[task - 'A'];
                max_count = 1;
            } else if (count[task - 'A'] == max_freq) {
                max_count++;
            }
        }

        int part_count = max_freq - 1;
        int part_length = n - (max_count - 1);
        int empty_slots = part_count * part_length;
        int available_tasks = tasks.size() - (max_freq * max_count);
        int idles = max(0, empty_slots - available_tasks);

        return tasks.size() + idles;
    }
};