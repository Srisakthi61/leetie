// ──────────────────────────────────────────────────
// Problem  : 1122. Relative Sort Array
// Difficulty: Easy
// Tags     : Array, Hash Table, Sorting, Counting Sort, Quicksort, Bubble Sort
// Link     : https://leetcode.com/problems/relative-sort-array/
// Runtime  : 3 ms (beats 18%)
// Memory   : 11252000 (beats 20%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); ++i) {
            rank[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            bool hasA = rank.count(a);
            bool hasB = rank.count(b);

            if (hasA && hasB) {
                return rank[a] < rank[b];
            } else if (hasA) {
                return true;
            } else if (hasB) {
                return false;
            } else {
                return a < b;
            }
        });

        return arr1;
    }
};