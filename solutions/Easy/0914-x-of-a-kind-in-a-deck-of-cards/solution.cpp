// ──────────────────────────────────────────────────
// Problem  : 914. X of a Kind in a Deck of Cards
// Difficulty: Easy
// Tags     : Array, Hash Table, Math, Counting, Number Theory, Euclidean Algorithm, Greatest Common Divisor
// Link     : https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8384000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (int card : deck) {
            count[card]++;
        }
        
        int g = -1;
        for (auto& [card, freq] : count) {
            if (g == -1) {
                g = freq;
            } else {
                g = std::gcd(g, freq);
            }
        }
        
        return g >= 2;
    }
};