// ──────────────────────────────────────────────────
// Problem  : 912. Sort an Array
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Sorting, Heap (Priority Queue), Merge Sort, Bucket Sort, Radix Sort, Counting Sort
// Link     : https://leetcode.com/problems/sort-an-array/
// Runtime  : 59 ms (beats 74%)
// Memory   : 73172000 (beats 70%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int p = left; p <= right; ++p) {
            nums[p] = temp[p];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};