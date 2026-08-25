// ──────────────────────────────────────────────────
// Problem  : 679. 24 Game
// Difficulty: Hard
// Tags     : Array, Math, Backtracking
// Link     : https://leetcode.com/problems/24-game/
// Runtime  : 4 ms (beats 0%)
// Memory   : 10700000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards) {
            nums.push_back(c);
        }
        return solve(nums);
    }

private:
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    vector<double> nextNums;
                    for (int k = 0; k < nums.size(); ++k) {
                        if (k != i && k != j) {
                            nextNums.push_back(nums[k]);
                        }
                    }

                    for (double val : compute(nums[i], nums[j])) {
                        nextNums.push_back(val);
                        if (solve(nextNums)) return true;
                        nextNums.pop_back();
                    }
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> res = {a + b, a - b, b - a, a * b};
        if (abs(b) > 1e-6) res.push_back(a / b);
        if (abs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
};