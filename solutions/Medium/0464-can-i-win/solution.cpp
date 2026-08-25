// ──────────────────────────────────────────────────
// Problem  : 464. Can I Win
// Difficulty: Medium
// Tags     : Math, Dynamic Programming, Bit Manipulation, Memoization, Game Theory, Bitmask
// Link     : https://leetcode.com/problems/can-i-win/
// Runtime  : 623 ms (beats 14%)
// Memory   : 91908000 (beats 36%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        return helper(maxChoosableInteger, desiredTotal, 0);
    }

    bool helper(int maxChoosableInteger, int desiredTotal, int state) {
        if (memo.count(state)) return memo[state];

        for (int i = 1; i <= maxChoosableInteger; ++i) {
            int mask = 1 << (i - 1);
            if ((state & mask) == 0) {
                if (desiredTotal <= i || !helper(maxChoosableInteger, desiredTotal - i, state | mask)) {
                    return memo[state] = true;
                }
            }
        }
        return memo[state] = false;
    }
};