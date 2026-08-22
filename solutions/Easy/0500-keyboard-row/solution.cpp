// ──────────────────────────────────────────────────
// Problem  : 500. Keyboard Row
// Difficulty: Easy
// Tags     : Array, Hash Table, String
// Link     : https://leetcode.com/problems/keyboard-row/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8720000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_set<char> row1(rows[0].begin(), rows[0].end());
        unordered_set<char> row2(rows[1].begin(), rows[1].end());
        unordered_set<char> row3(rows[2].begin(), rows[2].end());
        
        vector<string> result;
        
        for (const string& word : words) {
            if (word.empty()) continue;
            
            char firstChar = tolower(word[0]);
            const unordered_set<char>* targetRow = &row1;
            if (row2.count(firstChar)) targetRow = &row2;
            else if (row3.count(firstChar)) targetRow = &row3;
            
            bool valid = true;
            for (char c : word) {
                if (!targetRow->count(tolower(c))) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};