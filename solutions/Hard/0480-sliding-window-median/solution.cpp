// ──────────────────────────────────────────────────
// Problem  : 480. Sliding Window Median
// Difficulty: Hard
// Tags     : Array, Hash Table, Sliding Window, Heap (Priority Queue), Treap
// Link     : https://leetcode.com/problems/sliding-window-median/
// Runtime  : 75 ms (beats 53%)
// Memory   : 51324000 (beats 39%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large;
        vector<double> ans;

        auto insert = [&](int num) {
            if (small.empty() || num <= *small.rbegin()) {
                small.insert(num);
            } else {
                large.insert(num);
            }
            if (small.size() > large.size() + 1) {
                large.insert(*small.rbegin());
                small.erase(prev(small.end()));
            } else if (large.size() > small.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        };

        auto erase = [&](int num) {
            auto it = small.find(num);
            if (it != small.end()) {
                small.erase(it);
            } else {
                it = large.find(num);
                if (it != large.end()) {
                    large.erase(it);
                }
            }
            if (small.size() < large.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            } else if (small.size() > large.size() + 1) {
                large.insert(*small.rbegin());
                small.erase(prev(small.end()));
            }
        };

        auto getMedian = [&]() {
            if (k % 2 == 1) {
                return (double)*small.rbegin();
            } else {
                return ((double)*small.rbegin() + *large.begin()) / 2.0;
            }
        };

        for (int i = 0; i < k; ++i) {
            insert(nums[i]);
        }
        ans.push_back(getMedian());

        for (int i = k; i < nums.size(); ++i) {
            insert(nums[i]);
            erase(nums[i - k]);
            ans.push_back(getMedian());
        }

        return ans;
    }
};