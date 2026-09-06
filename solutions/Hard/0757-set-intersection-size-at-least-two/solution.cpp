// ──────────────────────────────────────────────────
// Problem  : 757. Set Intersection Size At Least Two
// Difficulty: Hard
// Tags     : Array, Greedy, Sorting
// Link     : https://leetcode.com/problems/set-intersection-size-at-least-two/
// Runtime  : 8 ms (beats 19%)
// Memory   : 21800000 (beats 66%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });

        int p1 = -1, p2 = -1;
        int ans = 0;

        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            bool has1 = (p1 >= start && p1 <= end);
            bool has2 = (p2 >= start && p2 <= end);

            if (has1 && has2) {
                continue;
            } else if (has2) {
                p1 = p2;
                p2 = end;
                ans++;
            } else {
                p1 = end - 1;
                p2 = end;
                ans += 2;
            }
        }

        return ans;
    }
};