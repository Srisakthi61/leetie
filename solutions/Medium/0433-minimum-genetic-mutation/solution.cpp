// ──────────────────────────────────────────────────
// Problem  : 433. Minimum Genetic Mutation
// Difficulty: Medium
// Tags     : Hash Table, String, Breadth-First Search, Bidirectional Search
// Link     : https://leetcode.com/problems/minimum-genetic-mutation/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9040000 (beats 16%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1;
        
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);
        
        char choices[] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()){
            auto [curr, steps] = q.front();
            q.pop();
            
            if (curr == endGene) return steps;
            
            for (int i = 0; i < curr.size(); i++){
                char original = curr[i];
                for (char c : choices){
                    if (c == original) continue;
                    curr[i] = c;
                    if (bankSet.count(curr) && !visited.count(curr)){
                        visited.insert(curr);
                        q.push({curr, steps + 1});
                    }
                }
                curr[i] = original;
            }
        }
        
        return -1;
    }
};