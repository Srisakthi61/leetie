// ──────────────────────────────────────────────────
// Problem  : 975. Odd Even Jump
// Difficulty: Hard
// Tags     : Array, Dynamic Programming, Stack, Sorting, Monotonic Stack, Ordered Set
// Link     : https://leetcode.com/problems/odd-even-jump/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8196000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int goodCount = 1;
        vector<bool> higher(n, false);
        vector<bool> lower(n, false);
        higher[n - 1] = true;
        lower[n - 1] = true;
        
        map<int, int> valIndexMap;
        valIndexMap[arr[n - 1]] = n - 1;
        
        for (int i = n - 2; i >= 0; --i) {
            auto itHigh = valIndexMap.lower_bound(arr[i]);
            if (itHigh != valIndexMap.end()) {
                higher[i] = lower[itHigh->second];
            }
            
            auto itLow = valIndexMap.upper_bound(arr[i]);
            if (itLow != valIndexMap.begin()) {
                lower[i] = higher[prev(itLow)->second];
            }
            
            if (higher[i]) {
                goodCount++;
            }
            valIndexMap[arr[i]] = i;
        }
        
        return goodCount;
    }
};