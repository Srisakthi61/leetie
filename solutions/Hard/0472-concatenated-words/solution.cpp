// ──────────────────────────────────────────────────
// Problem  : 472. Concatenated Words
// Difficulty: Hard
// Tags     : Array, String, Dynamic Programming, Depth-First Search, Trie, Sorting
// Link     : https://leetcode.com/problems/concatenated-words/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8528000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> word_set(words.begin(), words.end());
        vector<string> result;
        
        auto canForm = [&](string& word, auto& self) -> bool {
            int len = word.length();
            for (int i = 1; i < len; ++i) {
                string prefix = word.substr(0, i);
                string suffix = word.substr(i);
                
                if (word_set.count(prefix)) {
                    if (word_set.count(suffix) || self(suffix, self)) {
                        return true;
                    }
                }
            }
            return false;
        };
        
        for (string& word : words) {
            word_set.erase(word);
            if (canForm(word, canForm)) {
                result.push_back(word);
            }
            word_set.insert(word);
        }
        
        return result;
    }
};