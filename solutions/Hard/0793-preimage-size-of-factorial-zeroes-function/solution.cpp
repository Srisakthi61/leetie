// ──────────────────────────────────────────────────
// Problem  : 793. Preimage Size of Factorial Zeroes Function
// Difficulty: Hard
// Tags     : Math, Binary Search
// Link     : https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7948000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int preimageSizeFZF(int k) {
        auto countZeroes = [](long long x) {
            long long count = 0;
            for (long long d = 5; x / d > 0; d *= 5) {
                count += x / d;
            }
            return count;
        };

        auto findFirst = [&](int target) {
            long long low = 0, high = 5LL * (target + 1);
            long long ans = -1;
            while (low <= high) {
                long long mid = low + (high - low) / 2;
                if (countZeroes(mid) >= target) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        };

        long long left = findFirst(k);
        long long right = findFirst(k + 1);
        return right - left;
    }
};