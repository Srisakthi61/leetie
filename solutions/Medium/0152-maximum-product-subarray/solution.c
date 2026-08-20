// ──────────────────────────────────────────────────
// Problem  : 152. Maximum Product Subarray
// Difficulty: Medium
// Tags     : Array, Dynamic Programming
// Link     : https://leetcode.com/problems/maximum-product-subarray/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8476000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxProduct(int* nums, int numsSize) {
int max_so_far = nums[0];
int min_so_far = nums[0];
int result = nums[0];

for (int i = 1; i < numsSize; i++) {
int curr = nums[i];

if (curr < 0) {
int temp = max_so_far;
max_so_far = min_so_far;
min_so_far = temp;
}

max_so_far = (curr > max_so_far * curr) ? curr : max_so_far * curr;
min_so_far = (curr < min_so_far * curr) ? curr : min_so_far * curr;

if (max_so_far > result) {
            result = max_so_far;
                    }
                        }

                            return result;
                            }
