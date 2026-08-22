// ──────────────────────────────────────────────────
// Problem  : 497. Random Point in Non-overlapping Rectangles
// Difficulty: Medium
// Tags     : Array, Math, Binary Search, Reservoir Sampling, Prefix Sum, Ordered Set, Randomized
// Link     : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
// Runtime  : 0 ms (beats 0%)
// Memory   : 9140000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    vector<int> prefixSums;
    vector<vector<int>> rects;
    mt19937 rng;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int totalPoints = 0;
        rng.seed(chrono::steady_clock::now().time_since_epoch().count());
        
        for (const auto& rect : rects) {
            int points = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalPoints += points;
            prefixSums.push_back(totalPoints);
        }
    }
    
    vector<int> pick() {
        int target = uniform_int_distribution<int>(0, prefixSums.back() - 1)(rng);
        int rectIndex = upper_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin();
        
        int prevSum = rectIndex == 0 ? 0 : prefixSums[rectIndex - 1];
        int offset = target - prevSum;
        
        const auto& rect = rects[rectIndex];
        int width = rect[2] - rect[0] + 1;
        
        int x = rect[0] + (offset % width);
        int y = rect[1] + (offset / width);
        
        return {x, y};
    }
};