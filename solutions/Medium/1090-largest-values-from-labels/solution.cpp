// ──────────────────────────────────────────────────
// Problem  : 1090. Largest Values From Labels
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy, Sorting, Counting
// Link     : https://leetcode.com/problems/largest-values-from-labels/
// Runtime  : 7 ms (beats 70%)
// Memory   : 27580000 (beats 30%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {values[i], labels[i]};
        }

        sort(items.rbegin(), items.rend());

        unordered_map<int, int> labelCounts;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n && count < numWanted; ++i) {
            int val = items[i].first;
            int lab = items[i].second;

            if (labelCounts[lab] < useLimit) {
                labelCounts[lab]++;
                sum += val;
                count++;
            }
        }

        return sum;
    }
};