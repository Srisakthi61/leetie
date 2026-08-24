// ──────────────────────────────────────────────────
// Problem  : 648. Replace Words
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Trie
// Link     : https://leetcode.com/problems/replace-words/
// Runtime  : 776 ms (beats 7%)
// Memory   : 480836000 (beats 15%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, result = "";
        
        while (ss >> word) {
            string prefix = "";
            bool found = false;
            for (int i = 1; i <= word.length(); ++i) {
                prefix = word.substr(0, i);
                if (dict.count(prefix)) {
                    found = true;
                    break;
                }
            }
            if (!result.empty()) {
                result += " ";
            }
            result += found ? prefix : word;
        }
        
        return result;
    }
};