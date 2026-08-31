// ──────────────────────────────────────────────────
// Problem  : 810. Chalkboard XOR Game
// Difficulty: Hard
// Tags     : Array, Math, Bit Manipulation, Brainteaser, Game Theory, Zero-Sum Game, Impartial Game
// Link     : https://leetcode.com/problems/chalkboard-xor-game/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8008000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        if (xorSum == 0) {
            return true;
        }
        return nums.size() % 2 == 0;
    }
};