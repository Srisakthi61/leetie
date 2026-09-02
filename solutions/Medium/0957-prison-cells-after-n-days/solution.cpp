// ──────────────────────────────────────────────────
// Problem  : 957. Prison Cells After N Days
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Bit Manipulation, Floyd's Cycle Finding Algorithm
// Link     : https://leetcode.com/problems/prison-cells-after-n-days/
// Runtime  : 7 ms (beats 7%)
// Memory   : 16948000 (beats 5%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> seen;
        vector<vector<int>> history;
        
        for (int day = 0; day < n; ++day) {
            vector<int> next_cells(8, 0);
            for (int i = 1; i < 7; ++i) {
                if (cells[i - 1] == cells[i + 1]) {
                    next_cells[i] = 1;
                }
            }
            cells = next_cells;
            
            string s = "";
            for (int cell : cells) {
                s += to_string(cell);
            }
            
            if (seen.count(s)) {
                int cycle_length = day - seen[s];
                int remaining = (n - 1 - day) % cycle_length;
                return history[seen[s] + remaining];
            } else {
                seen[s] = day;
                history.push_back(cells);
            }
        }
        
        return cells;
    }
};