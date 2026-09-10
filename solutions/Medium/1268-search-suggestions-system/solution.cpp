// ──────────────────────────────────────────────────
// Problem  : 1268. Search Suggestions System
// Difficulty: Medium
// Tags     : Array, String, Binary Search, Trie, Sorting, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/search-suggestions-system/
// Runtime  : 14 ms (beats 78%)
// Memory   : 35788000 (beats 69%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string currentPrefix = "";

        for (char c : searchWord) {
            currentPrefix += c;
            vector<string> suggestions;
            
            auto it = lower_bound(products.begin(), products.end(), currentPrefix);
            
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                string product = *(it + i);
                if (product.rfind(currentPrefix, 0) == 0) {
                    suggestions.push_back(product);
                } else {
                    break;
                }
            }
            result.push_back(suggestions);
        }

        return result;
    }
};