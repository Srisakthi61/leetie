// ──────────────────────────────────────────────────
// Problem  : 599. Minimum Index Sum of Two Lists
// Difficulty: Easy
// Tags     : Array, Hash Table, String
// Link     : https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Runtime  : 13 ms (beats 84%)
// Memory   : 41280000 (beats 63%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        for (int i = 0; i < list1.size(); ++i) {
            map1[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int j = 0; j < list2.size(); ++j) {
            if (map1.count(list2[j])) {
                int sum = j + map1[list2[j]];
                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                } else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};