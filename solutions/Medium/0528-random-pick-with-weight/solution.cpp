// ──────────────────────────────────────────────────
// Problem  : 528. Random Pick with Weight
// Difficulty: Medium
// Tags     : Array, Math, Binary Search, Prefix Sum, Randomized
// Link     : https://leetcode.com/problems/random-pick-with-weight/
// Runtime  : 12 ms (beats 78%)
// Memory   : 47084000 (beats 74%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    vector<int> prefixSums;
    int totalSum;

public:
    Solution(vector<int>& w) {
        int sum = 0;
        for (int weight : w) {
            sum += weight;
            prefixSums.push_back(sum);
        }
        totalSum = sum;
    }
    
    int pickIndex() {
        int target = rand() % totalSum;
        auto it = upper_bound(prefixSums.begin(), prefixSums.end(), target);
        return distance(prefixSums.begin(), it);
    }
};