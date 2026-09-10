// ──────────────────────────────────────────────────
// Problem  : 1096. Brace Expansion II
// Difficulty: Hard
// Tags     : Hash Table, String, Backtracking, Stack, Breadth-First Search, Sorting
// Link     : https://leetcode.com/problems/brace-expansion-ii/
// Runtime  : 6 ms (beats 89%)
// Memory   : 15552000 (beats 60%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> seen;
        vector<string> queue = {""};
        
        for (int i = 0; i < expression.length(); ) {
            if (expression[i] == '{') {
                int j = i, bal = 0;
                while (j < expression.length()) {
                    if (expression[j] == '{') bal++;
                    else if (expression[j] == '}') bal--;
                    j++;
                    if (bal == 0) break;
                }
                string sub = expression.substr(i + 1, j - i - 2);
                vector<string> nextSub = braceExpansionII(sub);
                vector<string> temp;
                for (const string& prefix : queue) {
                    for (const string& word : nextSub) {
                        temp.push_back(prefix + word);
                    }
                }
                queue = temp;
                i = j;
            } else if (expression[i] == ',') {
                for (const string& word : queue) {
                    seen.insert(word);
                }
                queue = {""};
                i++;
            } else {
                string word(1, expression[i]);
                vector<string> temp;
                for (const string& prefix : queue) {
                    temp.push_back(prefix + word);
                }
                queue = temp;
                i++;
            }
        }
        
        for (const string& word : queue) {
            seen.insert(word);
        }
        
        return vector<string>(seen.begin(), seen.end());
    }
};