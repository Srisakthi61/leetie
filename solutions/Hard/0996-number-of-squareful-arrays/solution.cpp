// ──────────────────────────────────────────────────
// Problem  : 996. Number of Squareful Arrays
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Dynamic Programming, Backtracking, Bit Manipulation, Bitmask
// Link     : https://leetcode.com/problems/number-of-squareful-arrays/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8188000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    bool isSquare(int n) {
        int r = sqrt(n);
        return r * r == n;
    }

    void dfs(vector<int>& nums, vector<bool>& visited, int count, int prev, int& ans) {
        if (count == nums.size()) {
            ans++;
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            if (prev != -1 && !isSquare(prev + nums[i])) continue;

            visited[i] = true;
            dfs(nums, visited, count + 1, nums[i], ans);
            visited[i] = false;
        }
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        int ans = 0;
        dfs(nums, visited, 0, -1, ans);
        return ans;
    }
};