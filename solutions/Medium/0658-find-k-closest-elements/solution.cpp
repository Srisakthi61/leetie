// ──────────────────────────────────────────────────
// Problem  : 658. Find K Closest Elements
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Sliding Window, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/find-k-closest-elements/
// Runtime  : 0 ms (beats 100%)
// Memory   : 35856000 (beats 81%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};