// ──────────────────────────────────────────────────
// Problem  : 927. Three Equal Parts
// Difficulty: Hard
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/three-equal-parts/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8140000 (beats 0%)
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
        int i1 = 0, i2 = 0, i3 = 0;
        int j1 = 0, j2 = 0, j3 = 0;
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
        
        if (i1 + len <= j1 + 1 && i2 + len <= j2 + 1) {
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