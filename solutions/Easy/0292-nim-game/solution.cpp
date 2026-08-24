// ──────────────────────────────────────────────────
// Problem  : 292. Nim Game
// Difficulty: Easy
// Tags     : Math, Brainteaser, Minimax, Game Theory, Nim Game, Impartial Game
// Link     : https://leetcode.com/problems/nim-game/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7716000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};