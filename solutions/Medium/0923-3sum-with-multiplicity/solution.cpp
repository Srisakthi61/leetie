// ──────────────────────────────────────────────────
// Problem  : 923. 3Sum With Multiplicity
// Difficulty: Medium
// Tags     : Array, Hash Table, Two Pointers, Sorting, Counting
// Link     : https://leetcode.com/problems/3sum-with-multiplicity/
// Runtime  : 0 ms (beats 100%)
// Memory   : 14024000 (beats 90%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long count[101] = {0};
        for (int x : arr) {
            count[x]++;
        }
        
        long long ans = 0;
        long long MOD = 1e9 + 7;
        
        for (int i = 0; i <= 100; ++i) {
            for (int j = i; j <= 100; ++j) {
                int k = target - i - j;
                if (k < j || k > 100) continue;
                
                if (i == j && j == k) {
                    ans += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                } else if (i == j && j < k) {
                    ans += (count[i] * (count[i] - 1) / 2) * count[k];
                } else if (i < j && j == k) {
                    ans += count[i] * (count[j] * (count[j] - 1) / 2);
                } else if (i < j && j < k) {
                    ans += count[i] * count[j] * count[k];
                }
                ans %= MOD;
            }
        }
        
        return ans;
    }
};