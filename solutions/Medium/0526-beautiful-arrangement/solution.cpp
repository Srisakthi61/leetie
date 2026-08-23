// ──────────────────────────────────────────────────
// Problem  : 526. Beautiful Arrangement
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Backtracking, Bit Manipulation, Bitmask
// Link     : https://leetcode.com/problems/beautiful-arrangement/
// Runtime  : 46 ms (beats 48%)
// Memory   : 7908000 (beats 61%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;
        vector<bool> visited(n + 1, false);
        backtrack(n, 1, visited, ans);
        return ans;
    }

private:
    void backtrack(int n, int pos, vector<bool>& visited, int& ans) {
        if (pos > n) {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                backtrack(n, pos + 1, visited, ans);
                visited[i] = false;
            }
        }
    }
};