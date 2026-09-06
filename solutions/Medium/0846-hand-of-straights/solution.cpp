// ──────────────────────────────────────────────────
// Problem  : 846. Hand of Straights
// Difficulty: Medium
// Tags     : Array, Hash Table, Greedy, Sorting
// Link     : https://leetcode.com/problems/hand-of-straights/
// Runtime  : 38 ms (beats 58%)
// Memory   : 32408000 (beats 23%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        for (auto& [card, freq] : count) {
            if (freq > 0) {
                int countNeeded = freq;
                for (int i = 0; i < groupSize; ++i) {
                    if (count[card + i] < countNeeded) {
                        return false;
                    }
                    count[card + i] -= countNeeded;
                }
            }
        }
        return true;
    }
};