// ──────────────────────────────────────────────────
// Problem  : 632. Smallest Range Covering Elements from K Lists
// Difficulty: Hard
// Tags     : Array, Hash Table, Greedy, Sliding Window, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
// Runtime  : 80 ms (beats 60%)
// Memory   : 37668000 (beats 65%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);
        };
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> minHeap(cmp);
        int maxVal = INT_MIN;
        int k = nums.size();
        
        for (int i = 0; i < k; ++i) {
            minHeap.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }
        
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while (true) {
            auto [minVal, row, col] = minHeap.top();
            minHeap.pop();
            
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }
            
            if (col + 1 == nums[row].size()) {
                break;
            }
            
            int nextVal = nums[row][col + 1];
            minHeap.push({nextVal, row, col + 1});
            maxVal = max(maxVal, nextVal);
        }
        
        return {rangeStart, rangeEnd};
    }
};