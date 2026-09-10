// ──────────────────────────────────────────────────
// Problem  : 1202. Smallest String With Swaps
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union-Find, Sorting
// Link     : https://leetcode.com/problems/smallest-string-with-swaps/
// Runtime  : 28 ms (beats 70%)
// Memory   : 54300000 (beats 70%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        for (const auto& pair : pairs) {
            unite(pair[0], pair[1]);
        }
        
        unordered_map<int, vector<int>> indicesMap;
        unordered_map<int, string> charsMap;
        
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            indicesMap[root].push_back(i);
            charsMap[root].push_back(s[i]);
        }
        
        for (auto& [root, chars] : charsMap) {
            sort(chars.begin(), chars.end());
        }
        
        for (auto& [root, indices] : indicesMap) {
            auto& chars = charsMap[root];
            for (int i = 0; i < indices.size(); ++i) {
                s[indices[i]] = chars[i];
            }
        }
        
        return s;
    }
};