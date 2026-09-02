// ──────────────────────────────────────────────────
// Problem  : 989. Add to Array-Form of Integer
// Difficulty: Easy
// Tags     : Array, Math
// Link     : https://leetcode.com/problems/add-to-array-form-of-integer/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8296000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int n = num.size();
        int i = n - 1;
        int carry = 0;
        
        while (i >= 0 || k > 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num[i];
                i--;
            }
            if (k > 0) {
                sum += k % 10;
                k /= 10;
            }
            res.push_back(sum % 10);
            carry = sum / 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};