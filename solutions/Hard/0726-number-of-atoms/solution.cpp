// ──────────────────────────────────────────────────
// Problem  : 726. Number of Atoms
// Difficulty: Hard
// Tags     : Hash Table, String, Stack, Sorting
// Link     : https://leetcode.com/problems/number-of-atoms/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9648000 (beats 92%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        int n = formula.length();
        auto parseFormula = [&](auto& self) -> map<string, int> {
            map<string, int> counts;
            while (i < n && formula[i] != ')') {
                if (formula[i] == '(') {
                    i++;
                    map<string, int> inner = self(self);
                    int multiplier = 0;
                    while (i < n &&isdigit(formula[i])) {
                        multiplier = multiplier * 10 + (formula[i] - '0');
                        i++;
                    }
                    if (multiplier == 0) multiplier = 1;
                    for (auto& [elem, count] : inner) {
                        counts[elem] += count * multiplier;
                    }
                } else {
                    int start = i++;
                    while (i < n &&islower(formula[i])) {
                        i++;
                    }
                    string elem = formula.substr(start, i - start);
                    int multiplier = 0;
                    while (i < n &&isdigit(formula[i])) {
                        multiplier = multiplier * 10 + (formula[i] - '0');
                        i++;
                    }
                    if (multiplier == 0) multiplier = 1;
                    counts[elem] += multiplier;
                }
            }
            if (i < n && formula[i] == ')') {
                i++;
            }
            return counts;
        };

        map<string, int> finalCounts = parseFormula(parseFormula);
        string result = "";
        for (auto& [elem, count] : finalCounts) {
            result += elem;
            if (count > 1) {
                result += to_string(count);
            }
        }
        return result;
    }
};