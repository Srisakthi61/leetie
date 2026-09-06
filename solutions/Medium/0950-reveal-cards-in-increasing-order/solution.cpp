// ──────────────────────────────────────────────────
// Problem  : 950. Reveal Cards In Increasing Order
// Difficulty: Medium
// Tags     : Array, Queue, Sorting, Simulation
// Link     : https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12784000 (beats 22%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> result(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        for (int card : deck) {
            result[q.front()] = card;
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};