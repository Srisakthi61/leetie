// ──────────────────────────────────────────────────
// Problem  : 843. Guess the Word
// Difficulty: Hard
// Tags     : Array, Math, String, Minimax, Interactive, Game Theory
// Link     : https://leetcode.com/problems/guess-the-word/
// Runtime  : 4 ms (beats 0%)
// Memory   : 8260000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
    int countMatches(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < 6; ++i) {
            if (a[i] == b[i]) {
                matches++;
            }
        }
        return matches;
    }

public:
    void findSecretWord(vector<string>& words, Master& master) {
        for (int i = 0; i < 30; ++i) {
            unordered_map<string, int> count;
            for (const string& w1 : words) {
                int zeros = 0;
                for (const string& w2 : words) {
                    if (countMatches(w1, w2) == 0) {
                        zeros++;
                    }
                }
                count[w1] = zeros;
            }

            string bestGuess = words[0];
            int minZeros = count[bestGuess];
            for (const string& w : words) {
                if (count[w] < minZeros) {
                    minZeros = count[w];
                    bestGuess = w;
                }
            }

            int matches = master.guess(bestGuess);
            if (matches == 6) {
                return;
            }

            vector<string> nextWords;
            for (const string& w : words) {
                if (countMatches(bestGuess, w) == matches) {
                    nextWords.push_back(w);
                }
            }
            words = move(nextWords);
        }
    }
};