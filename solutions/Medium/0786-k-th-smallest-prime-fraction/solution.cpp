// ──────────────────────────────────────────────────
// Problem  : 786. K-th Smallest Prime Fraction
// Difficulty: Medium
// Tags     : Array, Two Pointers, Binary Search, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/k-th-smallest-prime-fraction/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11800000 (beats 97%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;
        vector<int> res = {0, 1};

        while (high - low > 1e-9) {
            double mid = low + (high - low) / 2.0;
            int count = 0;
            int p = 0, q = 1;
            int j = 1;

            for (int i = 0; i < n; ++i) {
                while (j < n && arr[i] > mid * arr[j]) {
                    j++;
                }
                count += (n - j);
                if (j < n && arr[i] * q > p * arr[j]) {
                    p = arr[i];
                    q = arr[j];
                }
            }

            if (count < k) {
                low = mid;
            } else {
                res[0] = p;
                res[1] = q;
                high = mid;
            }
        }

        return res;
    }
};