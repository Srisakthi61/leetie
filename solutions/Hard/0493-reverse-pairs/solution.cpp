// ──────────────────────────────────────────────────
// Problem  : 493. Reverse Pairs
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Segment Tree, Merge Sort, Ordered Set, Treap
// Link     : https://leetcode.com/problems/reverse-pairs/
// Runtime  : 487 ms (beats 67%)
// Memory   : 243592000 (beats 16%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int l = left, r = mid + 1;
        while (l <= mid && r <= right) {
            if (nums[l] <= nums[r]) {
                temp.push_back(nums[l++]);
            } else {
                temp.push_back(nums[r++]);
            }
        }
        while (l <= mid) {
            temp.push_back(nums[l++]);
        }
        while (r <= right) {
            temp.push_back(nums[r++]);
        }

        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i - left];
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        count += mergeAndCount(nums, left, mid, right);
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};