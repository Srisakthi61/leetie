// ──────────────────────────────────────────────────
// Problem  : 546. Remove Boxes
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Memoization
// Link     : https://leetcode.com/problems/remove-boxes/
// Runtime  : 36 ms (beats 79%)
// Memory   : 14576000 (beats 81%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int i, int j, int k) {
        if (i > j) return 0;
        if (dp[i][j][k] != 0) return dp[i][j][k];

        int original_i = i, original_k = k;
        while (i + 1 <= j && boxes[i + 1] == boxes[i]) {
            i++;
            k++;
        }

        int res = (k + 1) * (k + 1) + solve(boxes, i + 1, j, 0);

        for (int m = i + 1; m <= j; ++m) {
            if (boxes[m] == boxes[i]) {
                res = max(res, solve(boxes, i + 1, m - 1, 0) + solve(boxes, m, j, k + 1));
            }
        }

        return dp[original_i][j][original_k] = res;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};