// ──────────────────────────────────────────────────
// Problem  : 721. Accounts Merge
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Depth-First Search, Breadth-First Search, Union-Find, Sorting
// Link     : https://leetcode.com/problems/accounts-merge/
// Runtime  : 20 ms (beats 97%)
// Memory   : 38152000 (beats 92%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        auto find = [&](auto& self, int i) -> int {
            if (parent[i] == i) return i;
            return parent[i] = self(self, parent[i]);
        };

        unordered_map<string, int> emailToId;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string& email = accounts[i][j];
                if (emailToId.count(email)) {
                    int root1 = find(find, i);
                    int root2 = find(find, emailToId[email]);
                    if (root1 != root2) {
                        parent[root1] = root2;
                    }
                } else {
                    emailToId[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> components;
        for (auto& pair : emailToId) {
            string email = pair.first;
            int root = find(find, pair.second);
            components[root].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& pair : components) {
            int root = pair.first;
            vector<string>& emails = pair.second;
            sort(emails.begin(), emails.end());
            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[root][0]);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            result.push_back(mergedAccount);
        }

        return result;
    }
};