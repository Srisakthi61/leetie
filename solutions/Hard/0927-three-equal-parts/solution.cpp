// ──────────────────────────────────────────────────
// Problem  : 927. Three Equal Parts
// Difficulty: Hard
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/three-equal-parts/
// Runtime  : 3 ms (beats 36%)
// Memory   : 42572000 (beats 94%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int totalOnes = 0;
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }
        
        if (totalOnes % 3 != 0) {
            return {-1, -1};
        }
        
        if (totalOnes == 0) {
            return {0, 2};
        }
        
        int k = totalOnes / 3;
        int n = arr.size();
        
        int i1 = -1, j1 = -1;
        int i2 = -1, j2 = -1;
        int i3 = -1, j3 = -1;
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                count++;
                if (count == 1) i1 = i;
                if (count == k) j1 = i;
                if (count == k + 1) i2 = i;
                if (count == 2 * k) j2 = i;
                if (count == 2 * k + 1) i3 = i;
                if (count == 3 * k) j3 = i;
            }
        }
        
        int len = n - i3;
        
        if (i1 + len <= n && i2 + len <= n && i3 + len <= n) {
            for (int i = 0; i < len; ++i) {
                if (arr[i1 + i] != arr[i3 + i] || arr[i2 + i] != arr[i3 + i]) {
                    return {-1, -1};
                }
            }
            return {i1 + len - 1, i2 + len};
        }
        
        return {-1, -1};
    }
};