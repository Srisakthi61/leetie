// ──────────────────────────────────────────────────
// Problem  : 823. Binary Trees With Factors
// Difficulty: Medium
// Tags     : Array, Hash Table, Dynamic Programming, Sorting
// Link     : https://leetcode.com/problems/binary-trees-with-factors/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8132000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (dp.count(right)) {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[right]) % mod;
                    }
                }
            }
        }

        long long total = 0;
        for (auto& [val, count] : dp) {
            total = (total + count) % mod;
        }

        return total;
    }
};